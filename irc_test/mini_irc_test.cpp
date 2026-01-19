#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

// mini_irc_test.cpp
// Servidor ultra-simplificado que acepta conexiones no bloqueantes
// y hace echo de las líneas completas cuando detecta '\n'.

int set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) return -1;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int main(int argc, char **argv) {
    int port = 6667;
    if (argc >= 2) port = atoi(argv[1]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "socket() failed: " << strerror(errno) << std::endl;
        return 1;
    }

    int one = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
        std::cerr << "setsockopt() failed: " << strerror(errno) << std::endl;
        close(server_fd);
        return 1;
    }

    if (set_nonblocking(server_fd) < 0) {
        std::cerr << "fcntl() failed: " << strerror(errno) << std::endl;
        close(server_fd);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "bind() failed: " << strerror(errno) << std::endl;
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 10) < 0) {
        std::cerr << "listen() failed: " << strerror(errno) << std::endl;
        close(server_fd);
        return 1;
    }

    std::cout << "mini_irc_test listening on 0.0.0.0:" << port << std::endl;

    std::vector<struct pollfd> fds;
    std::map<int, std::string> buffers;

    struct pollfd pfd;
    pfd.fd = server_fd;
    pfd.events = POLLIN;
    pfd.revents = 0;
    fds.push_back(pfd);

    while (true) {
        int ret = poll(&fds[0], fds.size(), -1);
        if (ret < 0) {
            if (errno == EINTR) continue;
            std::cerr << "poll() failed: " << strerror(errno) << std::endl;
            break;
        }

        for (size_t i = 0; i < fds.size(); ++i) {
            if (fds[i].revents & POLLIN) {
                int fd = fds[i].fd;
                if (fd == server_fd) {
                    // aceptar conexiones en bucle hasta EAGAIN
                    while (true) {
                        struct sockaddr_in cli_addr;
                        socklen_t cli_len = sizeof(cli_addr);
                        int client_fd = accept(server_fd, (struct sockaddr *)&cli_addr, &cli_len);
                        if (client_fd < 0) {
                            if (errno == EAGAIN || errno == EWOULDBLOCK) break;
                            std::cerr << "accept() failed: " << strerror(errno) << std::endl;
                            break;
                        }
                        if (set_nonblocking(client_fd) < 0) {
                            std::cerr << "fcntl() client failed: " << strerror(errno) << std::endl;
                            close(client_fd);
                            continue;
                        }
                        struct pollfd cp;
                        cp.fd = client_fd;
                        cp.events = POLLIN;
                        cp.revents = 0;
                        fds.push_back(cp);
                        buffers[client_fd] = std::string();
                        std::cout << "New client fd=" << client_fd << std::endl;
                    }
                } else {
                    // leer datos del cliente
                    char buf[1024];
                    ssize_t n = recv(fd, buf, sizeof(buf), 0);
                    if (n <= 0) {
                        // cliente cerrado o error
                        std::cout << "client fd=" << fd << " closed" << std::endl;
                        close(fd);
                        buffers.erase(fd);
                        fds.erase(fds.begin() + i);
                        --i;
                        continue;
                    }
                    // añadir al buffer y procesar líneas completas
                    buffers[fd].append(buf, n);

                    // buscar líneas completas terminadas en '\n'
                    size_t pos;
                    while ((pos = buffers[fd].find('\n')) != std::string::npos) {
                        std::string line = buffers[fd].substr(0, pos);
                        // eliminar posible '\r' final (CRLF)
                        if (!line.empty() && line[line.size() - 1] == '\r')
                            line.erase(line.size() - 1);
                        // echo: devolver lo mismo + '\n'
                        line += '\n';
                        ssize_t sent = send(fd, line.c_str(), line.size(), 0);
                        if (sent < 0) {
                            std::cerr << "send() failed: " << strerror(errno) << std::endl;
                        }
                        buffers[fd].erase(0, pos + 1);
                    }
                }
            }
            if (fds[i].revents & (POLLHUP | POLLERR)) {
                int fd = fds[i].fd;
                std::cout << "client fd=" << fd << " hung up or error" << std::endl;
                close(fd);
                buffers.erase(fd);
                fds.erase(fds.begin() + i);
                --i;
            }
        }
    }

    // cleanup
    for (size_t i = 0; i < fds.size(); ++i) close(fds[i].fd);
    return 0;
}

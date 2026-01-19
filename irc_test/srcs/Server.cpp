#include "../includes/Server.hpp"
#include "../includes/Client.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cerrno>

static int set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) return -1;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

Server::Server(int port, const std::string &password)
    : _port(port), _password(password), _serverFd(-1) {}

Server::~Server() {
    if (_serverFd >= 0) close(_serverFd);
    for (std::map<int, Client*>::iterator it = _clients.begin();
         it != _clients.end(); ++it) {
        delete it->second;
        close(it->first);
    }
}

void Server::init() {
    _serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (_serverFd < 0) {
        std::cerr << "socket() failed: " << strerror(errno) << std::endl;
        return;
    }

    int one = 1;
    if (setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
        std::cerr << "setsockopt() failed: " << strerror(errno) << std::endl;
        close(_serverFd);
        _serverFd = -1;
        return;
    }

    if (set_nonblocking(_serverFd) < 0) {
        std::cerr << "fcntl() failed: " << strerror(errno) << std::endl;
        close(_serverFd);
        _serverFd = -1;
        return;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(_port);

    if (bind(_serverFd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "bind() failed: " << strerror(errno) << std::endl;
        close(_serverFd);
        _serverFd = -1;
        return;
    }

    if (listen(_serverFd, 10) < 0) {
        std::cerr << "listen() failed: " << strerror(errno) << std::endl;
        close(_serverFd);
        _serverFd = -1;
        return;
    }

    std::cout << "Server listening on 0.0.0.0:" << _port << std::endl;

    struct pollfd pfd;
    pfd.fd = _serverFd;
    pfd.events = POLLIN;
    pfd.revents = 0;
    _fds.push_back(pfd);
}

void Server::run() {
    if (_serverFd < 0) {
        std::cerr << "Server not initialized" << std::endl;
        return;
    }

    while (true) {
        int ret = poll(&_fds[0], _fds.size(), -1);
        if (ret < 0) {
            if (errno == EINTR) continue;
            std::cerr << "poll() failed: " << strerror(errno) << std::endl;
            break;
        }

        // Procesar eventos del poll
        for (size_t i = 0; i < _fds.size(); ++i) {
            if (_fds[i].revents & POLLIN) {
                int fd = _fds[i].fd;
                if (fd == _serverFd) {
                    acceptNewClient();
                } else {
                    handleClientData(fd);
                }
            }
            if (_fds[i].revents & (POLLHUP | POLLERR)) {
                int fd = _fds[i].fd;
                removeClient(fd);
                --i;
            }
        }
    }
}

void Server::acceptNewClient() {
    while (true) {
        struct sockaddr_in cli_addr;
        socklen_t cli_len = sizeof(cli_addr);
        int client_fd = accept(_serverFd, (struct sockaddr *)&cli_addr, &cli_len);
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
        struct pollfd pfd;
        pfd.fd = client_fd;
        pfd.events = POLLIN;
        pfd.revents = 0;
        _fds.push_back(pfd);

        Client *client = new Client(client_fd);
        _clients[client_fd] = client;
        std::cout << "New client fd=" << client_fd << std::endl;
    }
}

void Server::handleClientData(int fd) {
    if (_clients.find(fd) == _clients.end()) return;

    Client *client = _clients[fd];
    char buf[1024];
    ssize_t n = recv(fd, buf, sizeof(buf), 0);
    if (n <= 0) {
        removeClient(fd);
        return;
    }

    // Añadir datos al buffer del cliente
    client->appendToBuffer(buf, n);

    // Extraer líneas completas (comandos) del buffer
    std::string cmd;
    while (client->popLine(cmd)) {
        std::cout << "Client " << fd << " sent: [" << cmd << "]" << std::endl;
        // Aquí iría la lógica de procesamiento de comandos IRC
        // De momento, simple echo para validar fragmentos
        cmd += "\r\n";
        ssize_t sent = send(fd, cmd.c_str(), cmd.size(), 0);
        if (sent < 0) {
            std::cerr << "send() failed: " << strerror(errno) << std::endl;
        }
    }
}

void Server::removeClient(int fd) {
    std::cout << "Closing client fd=" << fd << std::endl;
    close(fd);
    if (_clients.find(fd) != _clients.end()) {
        delete _clients[fd];
        _clients.erase(fd);
    }
    // Remover el fd del array _fds
    for (size_t i = 0; i < _fds.size(); ++i) {
        if (_fds[i].fd == fd) {
            _fds.erase(_fds.begin() + i);
            break;
        }
    }
}

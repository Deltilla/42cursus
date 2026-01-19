#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <poll.h>

class Client;
class Channel;

class Server {

    private:
        int _port;
        std::string _password;
        int _serverFd;
        std::vector<struct pollfd> _fds; // Array de sockets para poll()
        std::map<int, Client*> _clients;  // Diccionario de clientes (fd -> puntero Client)

    public:
        Server(int port, const std::string &password);
        ~Server();

        void init();        // Crear socket, bind y listen
        void run();         // El bucle principal con poll()
        void acceptNewClient();
        void handleClientData(int fd);
        void removeClient(int fd);
};

#endif

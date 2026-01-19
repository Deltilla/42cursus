#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>

class Client {
  private:
    int _fd;
    std::string _buffer; // Buffer por cliente para ensamblar comandos fragmentados

  public:
    Client(int fd);
    ~Client();

    int getFd() const;
    const std::string &getBuffer() const;

    // Añade datos al buffer del cliente
    void appendToBuffer(const char *data, size_t len);

    // Si en el buffer hay al menos una línea terminada en '\n',
    // extrae la primera línea (sin el '\n') y la devuelve en out.
    // Retorna true si se extrajo una línea completa.
    bool popLine(std::string &out);
};

#endif

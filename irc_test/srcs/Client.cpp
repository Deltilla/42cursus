#include "../includes/Client.hpp"

Client::Client(int fd) : _fd(fd), _buffer() {}

Client::~Client() {}

int Client::getFd() const { return _fd; }

const std::string &Client::getBuffer() const { return _buffer; }

void Client::appendToBuffer(const char *data, size_t len) {
    _buffer.append(data, len);
}

bool Client::popLine(std::string &out) {
    size_t pos = _buffer.find('\n');
    if (pos == std::string::npos)
        return false;

    out = _buffer.substr(0, pos);
    // elimino CR final si existe (soporta CRLF)
    if (!out.empty() && out[out.size() - 1] == '\r')
        out.erase(out.size() - 1);

    _buffer.erase(0, pos + 1);
    return true;
}

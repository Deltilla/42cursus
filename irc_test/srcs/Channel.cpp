#include "../includes/Channel.hpp"

Channel::Channel(const std::string &name) : _name(name), _members() {}

Channel::~Channel() {}

const std::string &Channel::getName() const { return _name; }

void Channel::addMember(int fd) {
    for (size_t i = 0; i < _members.size(); ++i) {
        if (_members[i] == fd) return;
    }
    _members.push_back(fd);
}

void Channel::removeMember(int fd) {
    for (size_t i = 0; i < _members.size(); ++i) {
        if (_members[i] == fd) {
            _members.erase(_members.begin() + i);
            return;
        }
    }
}

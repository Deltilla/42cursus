#include "phonebook.hpp"

void contact::setIndex(int idx) {
    this->index = idx;
}

void contact::setAdded(bool status) {
    this->added = status;
}

void contact::setFirstName(const std::string& name) {
    this->first_name = name;
}

void contact::setLastName(const std::string& name) {
    this->last_name = name;
}

void contact::setNickname(const std::string& name) {
    this->nickname = name;
}

void contact::setPhone(const std::string& num) {
    this->phone = num;
}

void contact::setSecret(const std::string& sec) {
    this->secret = sec;
}

// Implementación de los getters
int contact::getIndex() const {
    return this->index;
}

bool contact::isAdded() const {
    return this->added;
}

std::string contact::getFirstName() const {
    return this->first_name;
}

std::string contact::getLastName() const {
    return this->last_name;
}

std::string contact::getNickname() const {
    return this->nickname;
}

std::string contact::getPhone() const {
    return this->phone;
}

std::string contact::getSecret() const {
    return this->secret;
}
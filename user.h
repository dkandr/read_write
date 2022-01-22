#pragma once
#include "message.h"

class User 
{
    std::string _name;
    std::string _login;
    std::string _pass;

public:
    User() = default;
    User(const std::string& name, const std::string& login, const std::string& pass) :
            _name(name), _login(login), _pass(pass) {}

    friend std::ifstream& operator>> (std::ifstream& is, User& obj) 
    {
        std::getline(is, obj._name);
        std::getline(is, obj._login);
        std::getline(is, obj._pass);
        return is;
    }
    friend std::ostream& operator<< (std::ostream& os, const User& obj) {
        os << obj._name << std::endl;
        os << obj._login << std::endl;
        os << obj._pass << std::endl;
        return os;
    } 
};
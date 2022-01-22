#pragma once
#include <string>
#include <fstream>

class Message 
{
    std::string _sender;
    std::string _receiver;
    std::string _text;

public:
    Message() = default;
    Message(const std::string& sender, const std::string& receiver, const std::string& text) :
            _sender(sender), _receiver(receiver), _text(text) {}

    friend std::ifstream& operator>> (std::ifstream& is, Message& obj) 
    {
        std::getline(is, obj._sender);
        std::getline(is, obj._receiver);
        std::getline(is, obj._text);
        return is;
    }
    friend std::ostream& operator<< (std::ostream& os, const Message& obj) {
        os << obj._sender << std::endl;
        os << obj._receiver << std::endl;
        os << obj._text << std::endl;
        return os;
    } 
};
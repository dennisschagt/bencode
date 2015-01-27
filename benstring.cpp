#include "benstring.h"
#include <cstring>
#include <iostream>

namespace Bencode {
    Benstring::Benstring() {
        this->ben_str = std::unique_ptr<char>(new char[0]);
        this->length = 0;
    }

    Benstring::Benstring(const char* str, int length) {
        this->ben_str = std::unique_ptr<char>(new char[length]);
        std::memcpy(this->ben_str.get(), str, length);
        this->length = length;
    }

    Benstring::Benstring(std::string str) : Benstring(str.c_str(), str.length()) { }

    Benstring::Benstring(const Benstring &other) {
        this->ben_str = std::unique_ptr<char>(new char[other.length]);
        std::memcpy(this->ben_str.get(), other.ben_str.get(), other.length);
        this->length = other.length;
    }

    Benstring::~Benstring() {
    }

    Element* Benstring::clone() {
        return new Benstring(this->ben_str.get(), this->length);
    }

    void Benstring::print() {
        std::cout << this->length << ':';
        for (int i = 0; i < length; ++i) {
            std::cout << this->ben_str.get()[i];
        }
    }
    
    void Benstring::convertToBencode(std::ostream &ss) {
        ss << this->length << ':';
        for (int i = 0; i < length; ++i) {
            ss << this->ben_str.get()[i];
        }
    }

    void Benstring::operator=(const Benstring &other) {
        this->ben_str = std::unique_ptr<char>(new char[other.length]);
        std::memcpy(this->ben_str.get(), other.ben_str.get(), other.length);
        this->length = other.length;
    }

    bool Benstring::operator==(const Benstring &other) {
        if (this->length != other.length) {
            return false;
        }
        for (int i = 0; i < this->length; ++i) {
            if (this->ben_str.get()[i] != other.ben_str.get()[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool Benstring::operator!=(const Benstring &other) {
        return !this->operator==(other);
    }

    Type Benstring::getType() {
        return Type::BENSTRING;
    }

    int Benstring::getLength() {
        return this->length;
    }

    // TODO: Document or at least check if given array is big enough
    int Benstring::getString(char* bytestring) {
        memcpy(bytestring, this->ben_str.get(), this->length);
        return this->length;
    }
    
    std::string Benstring::getString() {
        return std::string(this->ben_str.get(), this->length);
    }
}

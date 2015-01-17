#include "bencode.h"
#include <iostream>

// Check if parseD() actually returns null if the bencode does not describe a dictionary
bool test1() {
    std::string bencode = "le";
    Bencode::Parser parser;
    std::shared_ptr<Bencode::Dictionary> dictionary = parser.parseD(bencode.c_str(), bencode.length());
    if (dictionary != nullptr) {
        std::cout << "Bencoded list passed into parseD() should return a nullptr" << std::endl;
        return true;
    }
    return false;
}

// Check parsing negative integer
bool test2() {
    std::string bencode = "i-42e";
    Bencode::Parser parser;
    std::shared_ptr<Bencode::Integer> integer = parser.parseI(bencode.c_str(), bencode.length());
    if (integer->getValue() != -42) {
        std::cout << "Incorrect result when parsing negative number" << std::endl;
        return true;
    }
    return false;
}

int main() {
    bool error = false;
    error |= test1();
    error |= test2();
    return error;
}
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

int main() {
    bool error = false;
    error |= test1();
    return error;
}
#include "bencode.h"
#include <iostream>

// Check KeyValuePair.clone()
bool test1() {
    std::shared_ptr<Bencode::Integer> integer(new Bencode::Integer(5));
    Bencode::KeyValuePair pair1("test", integer);
    Bencode::KeyValuePair pair2 = pair1.clone();
    if (pair1.getKey() == pair2.getKey()) {
        std::cout << "KeyValuePair.clone() does not clone the key correctly" << std::endl;
        return true;
    }
    if (pair1.getValue() == pair2.getValue()) {
        std::cout << "KeyValuePair.clone() does not clone the value correctly" << std::endl;
        return true;
    }
    if (pair1 != pair2) {
        std::cout << "KeyValuePair clones are not equal." << std::endl;
        return true;
    }
    return false;
}

// Check if exception is generated when KeyValuePair is initialized with nullptr key or value
bool test2() {
    try {
        Bencode::KeyValuePair keyValuePair((std::shared_ptr<Bencode::Benstring>)nullptr, nullptr);
        std::cout << "Constructors for KeyValuePair should raise an exception if a nullptr is fed to it" << std::endl;
        return true;
    } catch (Bencode::NullptrElementException ex) {
    }
    try {
        Bencode::KeyValuePair keyValuePair("", nullptr);
        std::cout << "Constructors for KeyValuePair should raise an exception if a nullptr is fed to it" << std::endl;
        return true;
    } catch (Bencode::NullptrElementException ex) {
    }
    return false;
}

int main() {
    bool error = false;
    error |= test1();
    error |= test2();
    return error;
}

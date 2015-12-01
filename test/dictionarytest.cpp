#include "bencode.h"
#include <iostream>

// Check if exception is raised when adding a dupplicate key.
bool test1() {
    std::shared_ptr<Bencode::Integer> integer1(new Bencode::Integer);
    std::shared_ptr<Bencode::Integer> integer2(new Bencode::Integer);
    Bencode::KeyValuePair pair1("key1", integer1);
    Bencode::KeyValuePair pair2("key1", integer2);

    Bencode::Dictionary dictionary;
    dictionary.addKeyValuePair(pair1);
    try {
        dictionary.addKeyValuePair(pair2);
    } catch (Bencode::DuplicateKeyException ex) {
        return false;
    }
    std::cout << "Dictionary.addKeyValuePair() should raise an exeption when a second pair with the same key is added." << std::endl;
    return true;
}

// Two empty dictionaries are equal
bool test2() {
    Bencode::Dictionary dict1;
    Bencode::Dictionary dict2;
    if (dict1 != dict2) {
        std::cout << "Two empty dictionaries should be equal" << std::endl;
        return true;
    }
    return false;
}

// TODO: Check if dictionaries are always sorted correctly

int main() {
    bool error = false;
     error |= test1();
     error |= test2();
    return error;
}

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
    return false;
}

int main() {
    bool error = false;
    error |= test1();
    return error;
}
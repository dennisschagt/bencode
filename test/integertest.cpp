#include "bencode.h"
#include <iostream>

// Initial value test
bool test1() {
    Bencode::Integer integer;
    if (integer.getValue() != 0) {
        std::cout << "Initial value of bencode-Integer not 0" << std::endl;
        return true;
    }
    return false;
}

// Test .setValue() and .getValue()
bool test2() {
    Bencode::Integer integer;
    int value = 1;
    integer.setValue(value);
    if (integer.getValue() != value) {
        std::cout << "Bencode::Integer doesn't return the same value as the given value" << std::endl;
        return true;
    }
    return false;
}

// Check max value of bencode-Integer
bool test3() {
    int64_t max64bitValue = 9223372036854775807;
    Bencode::Integer integer(max64bitValue);
    if (integer.getValue() != max64bitValue) {
        std::cout << "Bencode::Integer should support 64-bit integers" << std::endl;
        return true;
    }
    return false;
}

int main() {
    bool error = false;
    error |= test1();
    error |= test2();
    error |= test3();
    return error;
}
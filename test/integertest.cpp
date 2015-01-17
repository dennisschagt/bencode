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
    int64_t max64bitValue = INT64_MAX;
    Bencode::Integer integer(max64bitValue);
    if (integer.getValue() != max64bitValue) {
        std::cout << "Bencode::Integer should support 64-bit integers" << std::endl;
        return true;
    }
    return false;
}

// Check min value of bencode-Integer
bool test4() {
    int64_t min64bitValue = INT64_MIN;
    Bencode::Integer integer(min64bitValue);
    if (integer.getValue() != min64bitValue) {
        std::cout << "Bencode::Integer should support 64-bit integers" << std::endl;
        return true;
    }
    return false;
}

// Check Integer equality function (equal)
bool test5() {
    Bencode::Integer int1(1);
    Bencode::Integer int2(1);
    if (int1 != int2) {
        std::cout << "Integers with equal value should be equal" << std::endl;
        return true;
    }
    return false;
}

// Check Integer equality function (not equal)
bool test6() {
    Bencode::Integer int1(1);
    Bencode::Integer int2(2);
    if (int1 == int2) {
        std::cout << "Integers with different values are not equal" << std::endl;
        return true;
    }
    return false;
}

int main() {
    bool error = false;
    error |= test1();
    error |= test2();
    error |= test3();
    error |= test4();
    error |= test5();
    error |= test6();
    return error;
}
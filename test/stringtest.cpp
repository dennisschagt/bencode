#include "bencode.h"
#include <iostream>

// Initial value test
bool test1() {
    Benstring benstring;
    if (benstring.getLength() != 0) {
        std::cout << "Length of empty string should be 0" << std::endl;
        return true;
    }
    return false;
}

// Check if length is returned when getting bytestring
bool test2() {
    Benstring benstring("test", 4);
    char* byteString = new char[benstring.getLength()];
    int length = benstring.getString(byteString);
    delete[] byteString;
    if (length != 4) {
        std::cout << "getString() should return the length of the string " << std::endl;
        return true;
    }
    return false;
}

// Check if std::string initialized Benstring returns the correct bytestring and length
bool test3() {
    std::string str = "test";
    Benstring benstring(str);
    char* byteString = new char[benstring.getLength()];
    int length = benstring.getString(byteString);
    if (length != static_cast<int>(str.length())) {
        std::cout << "String length not correct" << std::endl;
        delete[] byteString;
        return true;
    }
    for (int i = 0; i < length; ++i) {
        if (byteString[i] != str[i]) {
            std::cout << "Returned bytestring is not the same as the string with which the Benstring was initialized" << std::endl;
            delete[] byteString;
            return true;
        }
    }
    delete[] byteString;
    return false;
}

int main() {
    bool error = false;
    error |= test1();
    error |= test2();
    error |= test3();
    return error;
}
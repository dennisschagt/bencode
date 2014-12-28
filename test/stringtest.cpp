#include "bencode.h"
#include <iostream>

// Initial value test
bool test1() {
    Bencode::Benstring benstring;
    if (benstring.getLength() != 0) {
        std::cout << "Length of empty string should be 0" << std::endl;
        return true;
    }
    return false;
}

// Check if length is returned when getting bytestring
bool test2() {
    Bencode::Benstring benstring("test", 4);
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
    Bencode::Benstring benstring(str);
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

// Check Benstring equality function (equal)
bool test4() {
    Bencode::Benstring str1("test");
    Bencode::Benstring str2(std::string("test").c_str(), 4);
    if (str1 != str2) {
        std::cout << "Strings with equal content should be equal" << std::endl;
        return true;
    }
    return false;
}

// Check Benstring equality function (not equal)
bool test5() {
    Bencode::Benstring str1("test1");
    Bencode::Benstring str2("test2");
    if (str1 == str2) {
        std::cout << "Strings with different content are not equal" << std::endl;
        return true;
    }
    return false;
}

// TODO: Add test for testing `std::string getString()`

int main() {
    bool error = false;
    error |= test1();
    error |= test2();
    error |= test3();
    error |= test4();
    error |= test5();
    return error;
}
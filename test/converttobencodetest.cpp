#include "bencode.h"
#include <iostream>
#include <sstream>

bool testConversionOfParsedBencode(std::string bencode, std::string testName) {
    Bencode::Parser parser;
    auto element = parser.parse(bencode.c_str(), bencode.length());
    std::stringstream output;
    element->toBencode(output);
    if (output.str() != bencode) {
        std::cout << "Error in toBencode: " << testName << std::endl;
        return true;
    }
    return false;
}

// Empty dictionary test
bool test1() {
    std::string bencode = "de";
    return testConversionOfParsedBencode(bencode, "Empty dictionary");
}

// Benstring conversion test
bool test2() {
    std::string bencode = "4:test";
    return testConversionOfParsedBencode(bencode, "Benstring");
}

// Integer conversion test
bool test3() {
    std::string bencode = "i42e";
    return testConversionOfParsedBencode(bencode, "Integer");
}

// Negative integer conversion test
bool test4() {
    std::string bencode = "i-5e";
    return testConversionOfParsedBencode(bencode, "Negative integer");
}

// Empty list test
bool test5() {
    std::string bencode = "le";
    return testConversionOfParsedBencode(bencode, "Empty list");
}

// List with some elements test
bool test6() {
    std::string bencode = "l4:testdei42ee";
    return testConversionOfParsedBencode(bencode, "List with some elements");
}

// Dictionary with some elements test
bool test7() {
    std::string bencode = "d4:key112:random value9:other keyi42ee";
    return testConversionOfParsedBencode(bencode, "Dictionary with some elements");
}

int main() {
    bool error = false;
    error |= test1();
    error |= test2();
    error |= test3();
    error |= test4();
    error |= test5();
    error |= test6();
    error |= test7();
    return error;
}

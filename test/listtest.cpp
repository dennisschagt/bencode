#include "bencode.h"
#include <iostream>

// Check if exception is raised if NULL element is passed
bool test1() {
    List list;
    try {
        list.addElement(nullptr);
    } catch (const char* ex) {
        return false;
    }
    std::cout << "List.addElement() should raise an exception if a nullptr is fed to it" << std::endl;
    return true;
}

// Empty list should not enter body of foreach loop
bool test2() {
    List list;
    for (auto element : list) {
        std::cout << "Foreach loop over empty list should not enter loop body" << std::endl;
        return true;
    }
    return false;
}

// List.begin() should return the same element that is added to the list
bool test3() {
    List list;
    std::shared_ptr<Integer> integer(new Integer);
    list.addElement(integer);
    if (*list.begin() != integer) {
        std::cout << "*List.begin() should return the same element that is added to the list" << std::endl;
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
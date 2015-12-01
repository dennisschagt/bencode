#include "bencode.h"
#include <iostream>

// Check if exception is raised if NULL element is passed
bool test1() {
    Bencode::List list;
    try {
        list.addElement(nullptr);
    } catch (Bencode::NullptrElementException ex) {
        return false;
    }
    std::cout << "List.addElement() should raise an exception if a nullptr is fed to it" << std::endl;
    return true;
}

// Empty list should not enter body of foreach loop
bool test2() {
    Bencode::List list;
    for (auto element : list) {
        std::cout << "Foreach loop over empty list should not enter loop body" << std::endl;
        return true;
    }
    return false;
}

// List.begin() should return the same element that is added to the list;
// After one increase the iterator should be equal to List.end() (if there is one item in the list)
bool test3() {
    Bencode::List list;
    std::shared_ptr<Bencode::Integer> integer(new Bencode::Integer);
    list.addElement(integer);
    if (*list.begin() != integer) {
        std::cout << "*List.begin() should return the same element that is added to the list" << std::endl;
        return true;
    }
    auto beginIt = list.begin();
    ++beginIt;
    auto endIt = list.end();
    if (beginIt != endIt) {
        std::cout << "The iterators should be same after one increase as there is only one element in the list" << std::endl;
        return true;
    }
    return false;
}

// Two empty lists are equal
bool test4() {
    Bencode::List list1;
    Bencode::List list2;
    if (list1 != list2) {
        std::cout << "Two empty lists should be equal" << std::endl;
        return true;
    }
    return false;
}

// Two lists with different length are not equal
bool test5() {
    Bencode::List list1;
    Bencode::List list2;

    std::shared_ptr<Bencode::Integer> integer(new Bencode::Integer);
    list1.addElement(integer);

    if (list1 == list2) {
        std::cout << "Two lists with different length should not be equal" << std::endl;
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
    return error;
}

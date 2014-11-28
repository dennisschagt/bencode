#include "list.h"
#include <iostream>

List::List() {
}

List::~List() {
}

Element* List::clone() {
    // Deep copy list
    List* list =  new List();
    for (std::shared_ptr<Element> const& element : this->elements) {
        list->addElement(std::shared_ptr<Element>(element->clone()));
    }
    return list;
}

Type List::getType() {
    return Type::LIST;
}

void List::print() {
    std::cout << 'l';
    // Print List's contents
    for (std::shared_ptr<Element> const& element : this->elements) {
        element->print();
    }
    std::cout << 'e';
}

void List::addElement(std::shared_ptr<Element> element) {
    if (element) {
        this->elements.push_back(element);
    } else {
        throw "ERROR: shared_ptr to element should not be null";
    }
}

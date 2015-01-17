#include "list.h"
#include "exception.h"
#include <iostream>

namespace Bencode {
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
        for (std::shared_ptr<Element> element : this->elements) {
            element->print();
        }
        std::cout << 'e';
    }

    void List::addElement(std::shared_ptr<Element> element) {
        if (! element) {
            throw NullptrElementException();
        }
        this->elements.push_back(element);
    }

    std::shared_ptr<Element> List::getElement(int index) {
        return this->elements[index];
    }

    ListIterator List::begin() {
        return ListIterator(this, 0);
    }

    ListIterator List::end() {
        return ListIterator(this, this->elements.size());
    }

    bool ListIterator::operator!=(const ListIterator& other) {
        return curIndex != other.curIndex;
    }

    std::shared_ptr<Element> ListIterator::operator*() {
        return list->getElement(curIndex);
    }

    const ListIterator& ListIterator::operator++() {
        ++curIndex;
        return *this;
    }
}

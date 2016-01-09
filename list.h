#pragma once

#include "element.h"
#include <vector>
#include <memory>

namespace Bencode {
    class ListIterator;

    class List : public Element {
        std::vector<std::shared_ptr<Element>> elements;
    public:
        List();
        ~List();
        Element* clone();
        void toBencode(std::ostream &ss);
        bool operator==(const Element& other);
        bool operator==(const List& other);
        bool operator!=(const List& other);
        Type getType() const;
        void addElement(std::shared_ptr<Element> element);
        std::shared_ptr<Element> getElement(int index);
        ListIterator begin();
        ListIterator end();
    };

    class ListIterator {
        List* list;
        int curIndex;
    public:
        ListIterator(List* list, int index) : list(list), curIndex(index) { }
        bool operator!=(const ListIterator& other);
        std::shared_ptr<Element> operator*();
        const ListIterator& operator++();
    };
}


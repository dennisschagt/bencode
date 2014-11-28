#ifndef H_LIST
#define H_LIST

#include "element.h"
#include <vector>
#include <memory>

class ListIterator;

class List : public Element {
    std::vector<std::shared_ptr<Element>> elements;
public:
    List();
    ~List();
    Element* clone();
    void print();
    Type getType();
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


#endif

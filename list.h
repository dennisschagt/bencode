#ifndef H_LIST
#define H_LIST

#include "element.h"
#include <vector>
#include <memory>

class List : public Element {
    std::vector<std::shared_ptr<Element>> elements;
public:
    List();
    ~List();
    Element* clone();
    void print();
    Type getType();
    void addElement(std::shared_ptr<Element> element);
    std::shared_ptr<Element> getFirstElement();
    std::shared_ptr<Element> getNextElement();
};


#endif

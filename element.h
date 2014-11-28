#ifndef H_ELEMENT
#define H_ELEMENT

#include <memory>

enum class Type {DICTIONARY, BENSTRING, LIST, INTEGER};

class Element {
public:
    Element();
    virtual ~Element();
    virtual Element* clone() = 0;
    virtual void print() = 0;
    virtual Type getType() = 0;
};

#endif

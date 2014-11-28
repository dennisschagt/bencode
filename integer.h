#ifndef H_INTEGER
#define H_INTEGER

#include <cstdint>
#include "element.h"

class Integer: public Element {
    int64_t value;
public:
    Integer();
    Integer(int64_t value);
    ~Integer();
    Element* clone();
    void print();
    Type getType();
    void setValue(int64_t value);
    int64_t getValue();
};

#endif

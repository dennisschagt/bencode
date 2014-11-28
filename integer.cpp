#include "integer.h"
#include <iostream>

namespace Bencode {
    Integer::Integer() {
        this->value = 0;
    }

    Integer::Integer(int64_t value) {
        this->value = value;
    }

    Integer::~Integer() {
    }

    Element* Integer::clone() {
        return new Integer(this->value);
    }

    void Integer::print() {
        std::cout << 'i' << value << 'e';
    }

    void Integer::setValue(int64_t value) {
        this->value = value;
    }

    Type Integer::getType() {
        return Type::INTEGER;
    }

    int64_t Integer::getValue() {
        return this->value;
    }
}
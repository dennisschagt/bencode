#include "integer.h"
#include <sstream>

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
    
    void Integer::toBencode(std::ostream &ss) {
        ss << 'i' << value << 'e';
    }
    
    bool Integer::operator==(const Integer &other) {
        if (this->value == other.value) {
            return true;
        }
        return false;
    }
    
    bool Integer::operator!=(const Integer &other) {
        return !this->operator==(other);
    }

    bool Integer::operator==(const Element& other) {
        if (other.getType() != Type::INTEGER) {
            return false;
        }
        return this->operator==(dynamic_cast<const Integer&>(other));
    }

    void Integer::setValue(int64_t value) {
        this->value = value;
    }

    Type Integer::getType() const {
        return Type::INTEGER;
    }

    int64_t Integer::getValue() {
        return this->value;
    }
}

#pragma once

#include <cstdint>
#include "element.h"

namespace Bencode {
    class Integer: public Element {
        int64_t value;
    public:
        Integer();
        Integer(int64_t value);
        ~Integer();
        Element* clone();
        void toBencode(std::ostream &ss);
        bool operator==(const Integer &other);
        bool operator!=(const Integer &other);
        bool operator==(const Element& other);
        Type getType() const;
        void setValue(int64_t value);
        int64_t getValue();
    };
}

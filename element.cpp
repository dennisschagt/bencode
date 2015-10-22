#include "element.h"

namespace Bencode {
    Element::Element() {
    }

    Element::~Element() {
    }

    bool Element::operator!=(const Element& other) {
        return !this->operator==(other);
    }
}

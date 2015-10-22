#ifndef H_ELEMENT
#define H_ELEMENT

#include <memory>

namespace Bencode {
    enum class Type {DICTIONARY, BENSTRING, LIST, INTEGER};

    class Element {
    public:
        Element();
        virtual ~Element();
        virtual Element* clone() = 0;
        virtual Type getType() const = 0;
        virtual void toBencode(std::ostream &ss) = 0;
        virtual bool operator==(const Element& other) = 0;
        virtual bool operator!=(const Element& other);
    };
}

#endif

#ifndef H_DICTIONARY
#define H_DICTIONARY

#include "element.h"
#include "keyvaluepair.h"
#include <vector>
#include <memory>

namespace Bencode {
    class Dictionary : public Element {
        std::vector<KeyValuePair> keyValues;
    public:
        Dictionary();
        ~Dictionary();
        Element* clone();
        void print();
        Type getType();
        void addKeyValuePair(KeyValuePair pair);
        std::shared_ptr<Element> getValue(const Benstring& key);
    };
}

#endif

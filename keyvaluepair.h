#ifndef H_KEYVALUEPAIR
#define H_KEYVALUEPAIR

#include "benstring.h"
#include <memory>

namespace Bencode {
    class KeyValuePair {
        std::shared_ptr<Benstring> key;
        std::shared_ptr<Element> value;
    public:
        KeyValuePair(std::shared_ptr<Benstring>, std::shared_ptr<Element> value);
        KeyValuePair(const std::string key, std::shared_ptr<Element> value);
        KeyValuePair(const KeyValuePair& obj);
        ~KeyValuePair();
        KeyValuePair clone();
        void print();
        std::shared_ptr<Benstring> getKey();
        std::shared_ptr<Element> getValue();
    };
}

#endif

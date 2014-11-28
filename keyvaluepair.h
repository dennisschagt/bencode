#ifndef H_KEYVALUEPAIR
#define H_KEYVALUEPAIR

#include "benstring.h"
#include <memory>

class KeyValuePair {
    std::shared_ptr<Benstring> key;
    Element* value;
public:
    KeyValuePair(std::shared_ptr<Benstring>, Element* value);
    KeyValuePair(const std::string key, Element* value);
    KeyValuePair(const KeyValuePair& obj);
    KeyValuePair(KeyValuePair&& obj);
    ~KeyValuePair();
    void print();
    std::shared_ptr<Benstring> getKey();
    std::shared_ptr<Element> getValue();
};


#endif

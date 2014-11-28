#ifndef H_KEYVALUEPAIR
#define H_KEYVALUEPAIR

#include "benstring.h"
#include <memory>

class KeyValuePair {
    Benstring key;
    Element* value;
public:
    KeyValuePair(Benstring& key, Element* value);
    KeyValuePair(const std::string key, Element* value);
    KeyValuePair(const KeyValuePair& obj);
    KeyValuePair(KeyValuePair&& obj);
    ~KeyValuePair();
    void print();
    Benstring& getKey();
    std::unique_ptr<Element> getValue();
};


#endif

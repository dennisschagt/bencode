#include "keyvaluepair.h"
#include "exception.h"
#include <iostream>

namespace Bencode {
    KeyValuePair::KeyValuePair(std::shared_ptr<Benstring> key, std::shared_ptr<Element> value) : key(key), value(value) {
        if (!key || !value) {
            throw NullptrElementException();
        }
    }

    KeyValuePair::KeyValuePair(const std::string key, std::shared_ptr<Element> value) {
        if (! value) {
            throw NullptrElementException();
        }
        
        this->key = std::shared_ptr<Benstring>(new Benstring(key));
        this->value = value;
    }

    KeyValuePair::KeyValuePair(const KeyValuePair &obj) {
        this->key = obj.key;
        this->value = obj.value;
    }

    KeyValuePair::~KeyValuePair() {
    }

    KeyValuePair KeyValuePair::clone() {
        return KeyValuePair(std::shared_ptr<Benstring>((Benstring*)this->key->clone()),
                            std::shared_ptr<Element>(this->value->clone()));
    }

    void KeyValuePair::print() {
        key->print();
        value->print();
    }
    
    void KeyValuePair::convertToBencode(std::ostream &ss) {
        key->convertToBencode(ss);
        value->convertToBencode(ss);
    }

    std::shared_ptr<Benstring> KeyValuePair::getKey() {
        return this->key;
    }

    std::shared_ptr<Element> KeyValuePair::getValue() {
        return this->value;
    }
}

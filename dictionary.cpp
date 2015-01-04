#include "dictionary.h"
#include "exception.h"
#include <iostream>

namespace Bencode {
    Dictionary::Dictionary() {
    }

    Dictionary::~Dictionary() {
    }

    Element* Dictionary::clone() {
        Dictionary* dictionary = new Dictionary();
        // Deep copy keyValues
        for (KeyValuePair& keyValuePair : this->keyValues) {
            dictionary->addKeyValuePair(keyValuePair.clone());
        }
        return dictionary;
    }

    void Dictionary::print() {
        std::cout << "d";
        for (KeyValuePair keyValue : keyValues) {
            keyValue.print();
        }
        std::cout << "e";
    }

    Type Dictionary::getType() {
        return Type::DICTIONARY;
    }

    void Dictionary::addKeyValuePair(KeyValuePair pair) {
        this->keyValues.push_back(pair);
    }
    
    bool Dictionary::doesKeyExist(const Benstring& key) {
        for (KeyValuePair& keyValue : this->keyValues) {
            if (*keyValue.getKey() == key) {
                return true;
            }
        }
        return false;
    }

    std::shared_ptr<Element> Dictionary::getValue(const Benstring& key) {
        for (KeyValuePair& keyValue : this->keyValues) {
            if (*keyValue.getKey() == key) {
                return keyValue.getValue();
            }
        }
        throw KeyNotFoundException();
    }
    
    std::shared_ptr<Benstring> Dictionary::getValueBS(const Benstring& key) {
        auto value = this->getValue(key);
        if (value->getType() != Type::BENSTRING) {
            throw WrongTypeException();
        }
        return std::dynamic_pointer_cast<Benstring>(value);
    }
    
    std::shared_ptr<List> Dictionary::getValueL(const Benstring& key) {
        auto value = this->getValue(key);
        if (value->getType() != Type::LIST) {
            throw WrongTypeException();
        }
        return std::dynamic_pointer_cast<List>(this->getValue(key));
    }
    
    std::shared_ptr<Integer> Dictionary::getValueI(const Benstring& key) {
        auto value = this->getValue(key);
        if (value->getType() != Type::INTEGER) {
            throw WrongTypeException();
        }
        return std::dynamic_pointer_cast<Integer>(value);
    }
}
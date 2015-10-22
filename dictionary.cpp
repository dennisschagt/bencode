#include "dictionary.h"
#include "exception.h"
#include <sstream>

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
    
    void Dictionary::toBencode(std::ostream &ss) {
        ss << "d";
        for (KeyValuePair keyValue : keyValues) {
            keyValue.toBencode(ss);
        }
        ss << "e";
    }

    bool Dictionary::operator==(const Element& other) {
        (void)other;
        throw "Dictionary::operator==() Not implemented";
    }

    Type Dictionary::getType() const {
        return Type::DICTIONARY;
    }

    void Dictionary::addKeyValuePair(KeyValuePair pair) {
        // Check if key of KeyValuePair is not already in use in dictionary.
        Benstring key = *(pair.getKey().get());
        if (this->contains(key)) {
            throw DuplicateKeyException();
        }

        this->keyValues.push_back(pair);
    }
    
    bool Dictionary::contains(const Benstring& key) {
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
    
    std::shared_ptr<Benstring> Dictionary::getBenstring(const Benstring& key) {
        auto value = this->getValue(key);
        if (value->getType() != Type::BENSTRING) {
            throw WrongTypeException();
        }
        return std::dynamic_pointer_cast<Benstring>(value);
    }
    
    std::shared_ptr<List> Dictionary::getList(const Benstring& key) {
        auto value = this->getValue(key);
        if (value->getType() != Type::LIST) {
            throw WrongTypeException();
        }
        return std::dynamic_pointer_cast<List>(value);
    }
	
	std::shared_ptr<Dictionary> Dictionary::getDictionary(const Benstring& key) {
        auto value = this->getValue(key);
        if (value->getType() != Type::DICTIONARY) {
            throw WrongTypeException();
        }
        return std::dynamic_pointer_cast<Dictionary>(value);
    }
    
    std::shared_ptr<Integer> Dictionary::getInteger(const Benstring& key) {
        auto value = this->getValue(key);
        if (value->getType() != Type::INTEGER) {
            throw WrongTypeException();
        }
        return std::dynamic_pointer_cast<Integer>(value);
    }
}

#include "dictionary.h"
#include "exception.h"
#include <sstream>
#include <algorithm>

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
        if (other.getType() != Type::DICTIONARY) {
            return false;
        }
        return this->operator==(dynamic_cast<const Dictionary&>(other));
    }

    bool Dictionary::operator==(const Dictionary& other) {
        if (this->keyValues.size() != other.keyValues.size()) {
            return false;
        }
        int nOfKeyValues = this->keyValues.size();
        for (int i = 0; i < nOfKeyValues; ++i) {
            if (this->keyValues[i] != other.keyValues[i]) {
                return false;
            }
        }
        return true;
    }

    bool Dictionary::operator!=(const Dictionary& other) {
        return !this->operator==(other);
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

        // Sort KeyValuePairs in lexicographical key
        sort(this->keyValues.begin(), this->keyValues.end(),
            [](KeyValuePair leftKV, KeyValuePair rightKV) -> bool{
                auto leftKey = leftKV.getKey();
                auto rightKey = rightKV.getKey();

                char* left = new char[leftKey->getLength()];
                char* right = new char[rightKey->getLength()];

                int leftLength = leftKey->getString(left);
                int rightLength = rightKey->getString(right);

                return std::lexicographical_compare(left, left + leftLength, right, right + rightLength);
            });
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

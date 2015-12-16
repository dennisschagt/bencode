#include "keyvaluepair.h"
#include "exception.h"
#include <sstream>

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
    
    void KeyValuePair::toBencode(std::ostream &ss) {
        key->toBencode(ss);
        value->toBencode(ss);
    }

    bool KeyValuePair::operator==(const KeyValuePair &other) {
        if (*(this->key) != *(other.key)) {
            return false;
        }
        if (*(this->value) != *(other.value)) {
            return false;
        }
        return true;
    }

    bool KeyValuePair::operator!=(const KeyValuePair &other) {
        return !this->operator==(other);
    }

    std::shared_ptr<Benstring> KeyValuePair::getKey() {
        return this->key;
    }

    std::shared_ptr<Element> KeyValuePair::getValue() {
        return this->value;
    }

    bool KeyValuePair::compereKeyLexicograhpical(KeyValuePair &leftKV, KeyValuePair &rightKV) {
        auto leftKey = leftKV.getKey();
        auto rightKey = rightKV.getKey();

        char* left = new char[leftKey->getLength()];
        char* right = new char[rightKey->getLength()];

        int leftLength = leftKey->getString(left);
        int rightLength = rightKey->getString(right);

        return std::lexicographical_compare(left, left + leftLength, right, right + rightLength);
    };
}

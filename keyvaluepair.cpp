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

    std::shared_ptr<Benstring> KeyValuePair::getKey() const {
        return this->key;
    }

    std::shared_ptr<Element> KeyValuePair::getValue() const {
        return this->value;
    }

    bool KeyValuePair::compareKeyLexicograhpical(const KeyValuePair &leftKV, const KeyValuePair &rightKV) {
        const Benstring leftKey = *(leftKV.getKey().get());
        const Benstring rightKey = *(rightKV.getKey().get());
        return Benstring::compareLexicograhpical(leftKey, rightKey);
    };
}

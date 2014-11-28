#include "keyvaluepair.h"
#include <iostream>

KeyValuePair::KeyValuePair(std::shared_ptr<Benstring> key, std::shared_ptr<Element> value) : key(key), value(value) {
}

KeyValuePair::KeyValuePair(const std::string key, std::shared_ptr<Element> value) {
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

std::shared_ptr<Benstring> KeyValuePair::getKey() {
    return this->key;
}

std::shared_ptr<Element> KeyValuePair::getValue() {
    return this->value;
}
#include "keyvaluepair.h"
#include <iostream>

KeyValuePair::KeyValuePair(std::shared_ptr<Benstring> key, Element* value) : key(key), value(value->clone()) {
}

KeyValuePair::KeyValuePair(const std::string key, Element* value) {
    this->key = std::shared_ptr<Benstring>(new Benstring(key));
    this->value = value->clone();
}

KeyValuePair::KeyValuePair(const KeyValuePair &obj) {
    this->key = obj.key;
    this->value = obj.value->clone();
}

KeyValuePair::KeyValuePair(KeyValuePair&& obj) {
    this->key = obj.key;
    this->value = obj.value;
    obj.value = nullptr;
}

KeyValuePair::~KeyValuePair() {
    delete value;
}

void KeyValuePair::print() {
    key->print();
    value->print();
}

std::shared_ptr<Benstring> KeyValuePair::getKey() {
    return this->key;
}

std::shared_ptr<Element> KeyValuePair::getValue() {
    return std::shared_ptr<Element>(this->value->clone());
}
#include "keyvaluepair.h"
#include <iostream>

KeyValuePair::KeyValuePair(Benstring& key, Element* value) {
    this->key = key;
    this->value = value->clone();
}

KeyValuePair::KeyValuePair(const std::string key, Element* value) {
    this->key = Benstring(key);
    this->value = value->clone();
}

KeyValuePair::KeyValuePair(const KeyValuePair &obj) {
    this->key = obj.key;
    this->value = obj.value->clone();
}

KeyValuePair::KeyValuePair(KeyValuePair&& obj) {
    this->key = std::move(obj.key);
    this->value = obj.value;
    obj.value = nullptr;
}

KeyValuePair::~KeyValuePair() {
    delete value;
}

void KeyValuePair::print() {
    key.print();
    value->print();
}

Benstring& KeyValuePair::getKey() {
    return this->key;
}

std::unique_ptr<Element> KeyValuePair::getValue() {
    return std::unique_ptr<Element>(this->value->clone());
}
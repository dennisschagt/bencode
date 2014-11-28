#include "dictionary.h"
#include <iostream>

Dictionary::Dictionary() {
}

Dictionary::~Dictionary() {
}

Element* Dictionary::clone() {
    // Deep copy keyValues
    Dictionary* dictionary = new Dictionary();
    for (KeyValuePair& keyValuePair : this->keyValues) {
        dictionary->addKeyValuePair(keyValuePair);
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

std::unique_ptr<Element> Dictionary::getValue(const Benstring& key) {
    for (KeyValuePair& keyValue : this->keyValues) {
        if (keyValue.getKey() == key) {
            return std::unique_ptr<Element>(keyValue.getValue());
        }
    }
    // TODO: Throw specific exception type
    throw "ERROR: Key not found in dictionary";
}
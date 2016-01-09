#pragma once

#include "element.h"
#include "keyvaluepair.h"
#include "benstring.h"
#include "integer.h"
#include "list.h"
#include <vector>
#include <memory>

namespace Bencode {
    class Dictionary : public Element {
        std::vector<KeyValuePair> keyValues;
    public:
        Dictionary();
        ~Dictionary();
        Element* clone();
        void toBencode(std::ostream &ss);
        bool operator==(const Element& other);
        bool operator==(const Dictionary& other);
        bool operator!=(const Dictionary& other);
        Type getType() const;
        void addKeyValuePair(KeyValuePair pair);
        bool contains(const Benstring& key);
        std::shared_ptr<Element> getValue(const Benstring& key);
        std::shared_ptr<Benstring> getBenstring(const Benstring& key);
        std::shared_ptr<List> getList(const Benstring& key);
        std::shared_ptr<Dictionary> getDictionary(const Benstring& key);
        std::shared_ptr<Integer> getInteger(const Benstring& key);
    };
}

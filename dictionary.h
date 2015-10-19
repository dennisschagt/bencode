#ifndef H_DICTIONARY
#define H_DICTIONARY

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
        Type getType();
        void addKeyValuePair(KeyValuePair pair);
        bool contains(const Benstring& key);
        std::shared_ptr<Element> getValue(const Benstring& key);
        std::shared_ptr<Benstring> getBenstring(const Benstring& key);
        std::shared_ptr<List> getList(const Benstring& key);
        std::shared_ptr<Dictionary> getDictionary(const Benstring& key);
        std::shared_ptr<Integer> getInteger(const Benstring& key);
    };
}

#endif

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
        void convertToBencode(std::ostream &ss);
        Type getType();
        void addKeyValuePair(KeyValuePair pair);
        bool doesKeyExist(const Benstring& key);
        std::shared_ptr<Element> getValue(const Benstring& key);
        std::shared_ptr<Benstring> getValueBS(const Benstring& key);
        std::shared_ptr<List> getValueL(const Benstring& key);
        std::shared_ptr<Dictionary> getValueD(const Benstring& key);
        std::shared_ptr<Integer> getValueI(const Benstring& key);
    };
}

#endif

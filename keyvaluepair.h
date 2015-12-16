#ifndef H_KEYVALUEPAIR
#define H_KEYVALUEPAIR

#include "benstring.h"
#include <memory>

namespace Bencode {
    class KeyValuePair {
        std::shared_ptr<Benstring> key;
        std::shared_ptr<Element> value;
    public:
        KeyValuePair(std::shared_ptr<Benstring> key, std::shared_ptr<Element> value);
        KeyValuePair(const std::string key, std::shared_ptr<Element> value);
        KeyValuePair(const KeyValuePair& obj);
        ~KeyValuePair();
        KeyValuePair clone();
        void toBencode(std::ostream &ss);
        bool operator==(const KeyValuePair &other);
        bool operator!=(const KeyValuePair &other);
        std::shared_ptr<Benstring> getKey() const;
        std::shared_ptr<Element> getValue() const;
        static bool compareKeyLexicograhpical(const KeyValuePair &leftKV,
                                              const KeyValuePair &rightKV);
    };
}

#endif

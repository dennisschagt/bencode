#ifndef H_PARSER
#define H_PARSER

#include "element.h"
#include "dictionary.h"
#include <memory>
#include <stack>

namespace Bencode {
    class Parser {
    public:
        Parser();
        ~Parser();
        std::shared_ptr<Element> parse(const char* input, int length, int *usedLength = nullptr);
        std::shared_ptr<Element> parse(const std::string input);
        std::shared_ptr<Dictionary> parseD(const char* input, int length);
        std::shared_ptr<List> parseL(const char* input, int length);
        std::shared_ptr<Benstring> parseB(const char* input, int length);
        std::shared_ptr<Integer> parseI(const char* input, int length);
    };
}

#endif // H_PARSER

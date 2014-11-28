#ifndef H_PARSER
#define H_PARSER

#include "element.h"
#include <memory>
#include <stack>

class Parser {
public:
    Parser();
    ~Parser();
    std::shared_ptr<Element> parse(const char* input, int length, int *usedLength = nullptr);
    std::shared_ptr<Element> parse(const std::string input);
};

#endif // H_PARSER

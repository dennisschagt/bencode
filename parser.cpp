#include "parser.h"
#include "benstring.h"
#include "keyvaluepair.h"
#include "integer.h"
#include "list.h"
#include "exception.h"

namespace Bencode {
    Parser::Parser() {
    }

    Parser::~Parser() {
    }

    std::shared_ptr<Element> Parser::parse(const char* input, int length, int *usedLength) {
        std::shared_ptr<Element> currentElement;
        int curPos = 0;
        switch(input[curPos]) {
        case 'd': { // Parse Dictionary
            std::shared_ptr<Dictionary> dictionary(new Dictionary());
            currentElement = dictionary;
            curPos++;
            // Parse dictionary entries
            while (curPos < length && input[curPos] != 'e') {
                // Parse key
                int keyBenLength;
                std::shared_ptr<Benstring> key = std::dynamic_pointer_cast<Benstring>(parse(input + curPos, length - curPos, &keyBenLength));
                curPos += keyBenLength;
                // Check if key is a benString
                if (key == nullptr) {
                    throw ParseException();
                }
                // Parse value
                int valueBenLength;
                std::shared_ptr<Element> value = parse(input + curPos, length - curPos, &valueBenLength);
                curPos += valueBenLength;
                // Add key with value to dictionary
                dictionary->addKeyValuePair(KeyValuePair(key, value));
            }
            curPos++;
            break;}
        case '0'...'9': { // Parse Benstring
            int strLength = 0;
            // Determine string length
            while (curPos < length && input[curPos] != ':') {
                if (input[curPos] < '0' || input[curPos] > '9') {
                    throw ParseException();
                }
                strLength = 10 * strLength + (input[curPos] - '0');
                curPos++;
            }
            if (curPos + strLength >= length) {
                throw EndOfInputException();
            }
            curPos++;
            currentElement = std::shared_ptr<Element>(new Benstring(input + curPos, strLength));
            curPos += strLength;
            break;}
        case 'l': // Parse List
            curPos++;
            currentElement = std::shared_ptr<Element>(new List());
            while (curPos < length && input[curPos] != 'e') {
                // Parse element
                int elementBenLength;
                std::shared_ptr<Element> element = parse(input + curPos, length - curPos, &elementBenLength);
                ((List*)currentElement.get())->addElement(element);
                curPos += elementBenLength;
            }
            curPos++;
            break;
        case 'i':{ // Parse Integer
            curPos++;
            int64_t value = 0;
            bool isNegative = false;
            if (curPos < length && input[curPos] == '-') {
                isNegative = true;
                curPos++;
            }
            while (curPos < length && input[curPos] != 'e') {
                if (input[curPos] < '0' || input[curPos] > '9') {
                    throw ParseException();
                }
                value = 10 * value + (input[curPos] - '0');
                curPos++;
            }
            if (isNegative) {
                value *= -1;
            }
            currentElement = std::shared_ptr<Element>(new Integer(value));
            curPos++;
            break;}
        default: // Not a valid start for a bencode element
            throw ParseException();
        }
        if (curPos > length) {
            throw EndOfInputException();
        }
        if (usedLength) {
            *usedLength = curPos;
        }
        return currentElement;
    }

    std::shared_ptr<Element> Parser::parse(const std::string input) {
        return this->parse(input.c_str(), input.length());
    }
    
    std::shared_ptr<Dictionary> Parser::parseD(const char* input, int length) {
        return std::dynamic_pointer_cast<Dictionary>(this->parse(input, length));
    }
    
    std::shared_ptr<List> Parser::parseL(const char* input, int length) {
        return std::dynamic_pointer_cast<List>(this->parse(input, length));
    }
    
    std::shared_ptr<Benstring> Parser::parseB(const char* input, int length) {
        return std::dynamic_pointer_cast<Benstring>(this->parse(input, length));
    }
    
    std::shared_ptr<Integer> Parser::parseI(const char* input, int length) {
        return std::dynamic_pointer_cast<Integer>(this->parse(input, length));
    }
}

#ifndef H_BENSTRING
#define H_BENSTRING

#include "element.h"
#include <memory>

namespace Bencode {
    class Benstring : public Element {
        std::unique_ptr<char> ben_str = nullptr;
        int length = 0;
    public:
        Benstring();
        Benstring(const char* str, int length);
        Benstring(std::string str);
        Benstring(const Benstring &obj);
        Benstring(Benstring&& obj);
        ~Benstring();
        Element* clone();
        void print();
        void operator=(const Benstring &other);
        bool operator==(const Benstring &other);
        bool operator!=(const Benstring &other);
        Type getType();
        int getLength();
        int getString(char* byteString);
        std::string getString();
    };
}

#endif

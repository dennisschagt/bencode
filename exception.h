#ifndef H_EXCEPTION
#define H_EXCEPTION

namespace Bencode {
    class Exception {
    
    };
    
    class KeyNotFoundException : public Exception {
    
    };
    
    class ParseException : public Exception {
    
    };
    
    class WrongTypeException : public Exception {
    
    };
}

#endif
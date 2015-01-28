#ifndef H_EXCEPTION
#define H_EXCEPTION

namespace Bencode {
    class Exception {
    };
    
    class KeyNotFoundException : public Exception {
    };
    
    class WrongTypeException : public Exception {
    };
    
    // Exception that is thrown when a nullptr is being added to, for example, a list or a dictionary
    class NullptrElementException : public Exception {
    };
    
    class ParseException : public Exception {
    };
    
    class EndOfInputException : public ParseException {
    };
}

#endif

/*
    WordProcessor.hpp

    Declarations for reading words from files
*/

#ifndef INCLUDED_WORDPROCESSOR_HPP
#define INCLUDED_WORDPROCESSOR_HPP

#include <istream>
#include <functional>

class WordProcessor {
public:

    // constructor with input stream and processWord function
    WordProcessor(std::istream& in);

    // read the words and apply the processWord
    void read();

    // destructor
    virtual ~WordProcessor() = default;

private:
    std::istream& input;
};

#endif

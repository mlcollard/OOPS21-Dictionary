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
    WordProcessor(std::istream& in, std::function<bool(const std::string& word)> processWord);

    // read the words and apply the processWord
    void read();

private:
    std::istream& input;
    std::function<bool(const std::string& word)> processWord;
};

#endif

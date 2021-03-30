/*
    DictionaryWordProcessor.hpp

    Declarations for dictionary creation
*/

#ifndef INCLUDED_DICTIONARYWORDPROCESSOR_HPP
#define INCLUDED_DICTIONARYWORDPROCESSOR_HPP

#include "WordProcessor.hpp"
#include <istream>
#include <ostream>
#include <string>
#include <set>

class DictionaryWordProcessor : public WordProcessor {
public:
    DictionaryWordProcessor(std::istream& in);

    // output words to out stream
    void outputWords(std::ostream& out) const;

private:
    std::set<std::string> words;
};

#endif

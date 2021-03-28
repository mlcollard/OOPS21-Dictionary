/*
    WordProcessor.cpp

    Definitions for word reading functions
*/

#include "WordProcessor.hpp"
#include <ctype.h>
#include <vector>
#include <locale>
#include <memory>

namespace {

const auto temp = std::ctype<char>::classic_table();
std::vector<std::ctype<char>::mask> bar(temp, temp + std::ctype<char>::table_size);

// bar[' '] ^= ctype_base::space;
// bar['\t'] &= ~(ctype_base::space | ctype_base::cntrl);
// bar[':'] |= ctype_base::space;

// struct word_delimiter : std::ctype<char> {
//     word_delimiter()
//         : std::ctype<char>(get_table())
//     {}

//     static mask const* get_table() {
//         static mask rc[table_size];
//         rc[':'] = std::ctype_base::space;
//         rc['\n'] = std::ctype_base::space;
//         return &rc[0];
//     }
// };

}

// constructor with input stream and processWord function
WordProcessor::WordProcessor(std::istream& in, std::function<bool(const std::string& word)> processWord)
    : input(in), processWord(processWord)
{}

// read all the words from a file and apply process() to them
void WordProcessor::read() {

    // word separator for :,(,),.,;,",&,<,>,_,[,],,
    const auto temp = std::ctype<char>::classic_table();
    std::vector<std::ctype<char>::mask> mask(temp, temp + std::ctype<char>::table_size);
    mask[':'] |= std::ctype_base::space;
    mask['('] |= std::ctype_base::space;
    mask[')'] |= std::ctype_base::space;
    mask['.'] |= std::ctype_base::space;
    mask[';'] |= std::ctype_base::space;
    mask['"'] |= std::ctype_base::space;
    mask['&'] |= std::ctype_base::space;
    mask['<'] |= std::ctype_base::space;
    mask['>'] |= std::ctype_base::space;
    mask['_'] |= std::ctype_base::space;
    mask['['] |= std::ctype_base::space;
    mask[']'] |= std::ctype_base::space;
    mask[','] |= std::ctype_base::space;

    // add new mask to locale
    // note use of new without delete (standard technique for this)
    input.imbue(std::locale(input.getloc(), new std::ctype<char>(std::data(mask))));

    // read and process all words in the file
    std::string word;
    while (input >> word) {

        // words must begin with an alphabetic character
        if (!isalpha(word[0]))
            continue;

        // apply the processing stopping if false
        if (!processWord(word))
            break;
    }
}

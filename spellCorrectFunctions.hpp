#ifndef SPELLCORRECTFUNCTIONS_HPP
#define SPELLCORRECTFUNCTIONS_HPP

#include <vector>
#include <string>
#include "hashSet.hpp"

// These functions are all for finding out possible suggestions to what the misspelled words could be

// This function takes in a misspelled word and runs it through a series of common ways to misspell
// that word and sees if its inside the input wordBank.
// findSuggestions returns a vector of strings of possible suggestions
std::vector<std::string> findSuggestions(const std::string& word, const hashSet& wordBank);

// notIn takes a potential correct spelling and sees if its already inside the suggestions vector.
bool notIn(const std::string& word, const std::vector<std::string>& suggestions);

// wrongOrdering checks to see if switching one letter with a close letter is a word inside the wordBank.
void wrongOrdering(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank);

// missingLetter checks to see if adding a letter to a spot in the word produces a word inside the wordBank.
void missingLetter(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank);

// additionalLetter checks to see if adding an additional letter produces a word inside the wordBank.
void additionalLetter(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank);

// differentLetter checks to see if switching each one of the letters with a different one produces a word inside the
// wordBank.
void differentLetter(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank); 

// noSpace checks to see if adding a space between each letter produces a word inside the wordBank.
void noSpace(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank);

#endif
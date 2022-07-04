#ifndef LOADFILEFUNCTIONS_HPP
#define LOADFILEFUNCTIONS_HPP

#include "hashSet.hpp"
#include <fstream>
#include <string>
#include <sstream>

// these functions are specifically to help load the file into the spell checker

// loads all the words from an ifstream into the input hashSet
void loadAllWords(std::ifstream& inputFile, hashSet& h);

// puts all words in a line into input vector of strings
void inputToVector(std::string line, std::vector<std::string>& words);

#endif
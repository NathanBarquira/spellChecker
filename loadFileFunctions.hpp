#ifndef LOADFILEFUNCTIONS_HPP
#define LOADFILEFUNCTIONS_HPP

#include "hashSet.hpp"
#include <fstream>
#include <string>

// these functions are specifically to help load the file into the spell checker

// loads all the words from an ifstream into the input hashSet
void loadAllWords(std::ifstream& inputFile, hashSet& h);

#endif
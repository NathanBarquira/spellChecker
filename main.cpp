#include <iostream>
#include <fstream>
#include "hashSet.hpp"
#include "loadFileFunctions.hpp"

// The actual spell checker program.
// This program uses the self-implemented data structures to
// create a working spell checker. The goal is to potentially
// create a working grammar checker as well

int main()
{
    // this will be the data structure that holds the words
    hashSet wordBank;
    
    // the users input for the file to open
    std::string file;
    std::getline(std::cin, file);
    std::ifstream inputFile(file);

    // loops until you get a valid file
    while (inputFile.fail())
    {
        std::cout << "\"" << file << "\" is not a valid file, please type again. " << std::endl;
        inputFile.clear();
        std::getline(std::cin, file);
        std::ifstream inputFile(file);
    }

    // puts all the words into the wordBank
    loadAllWords(inputFile, wordBank);

    return 0;
}
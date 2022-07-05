#include <iostream>
#include <fstream>
#include "hashSet.hpp"
#include "loadFileFunctions.hpp"
#include "spellCorrectFunctions.hpp"

// The actual spell checker program.
// This program uses the self-implemented data structures to
// create a working spell checker. The goal is to potentially
// create a working grammar checker as well

// notes:
// * currently only supports all lowercase letter words.

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

    // checking to see if inputWords is correct
    // std::fstream checkWords;
    // checkWords.open("vector_file.txt",ios_base::out);
 
    // for(std::string::size_type i = 0; i < wordBank.size(); i++)
    // {
    //     checkWords << v[i] << std::endl;

    // }
 
    // checkWords.close();
    std::vector<std::string> allWords(wordBank.allToVector());
    std::cout << "DEBUG: should be 1000: " << allWords.size() << std::endl;
    // for (std::string::size_type i = 0; i < allWords.size(); i++)
    // {
    //     print(allWords[i]);
    // }


    // the input that will be spell checked
    std::string textInput;
    
    // vector of strings that will hold all the words from the input
    std::vector<std::string> words;

    // transferring the input to a vector of words
    std::getline(std::cin, textInput);
    inputToVector(textInput, words);
    

    print("DEBUG: all of the words");
    printVector(words);

    std::getline(std::cin, textInput);

    for (std::string::size_type i = 0; i < words.size(); ++i)
    {
        std::cout << "DEBUG: should be current word suggestion: " << words[i] << std::endl;
        std::getline(std::cin, textInput);
        if (!wordBank.contains(words[i]))
        {
            std::vector<std::string> suggestions(findSuggestions(words[i], wordBank));
            if (suggestions.size() > 0)
            {
                std::cout << "By \"" << words[i] << "\", do you mean..." << std::endl;
                for (std::string::size_type i = 0; i < suggestions.size(); ++i)
                {
                    std::cout << suggestions[i] << "?" << std::endl;
                }
                std::getline(std::cin, textInput);
            }
        }
        
    }
    
    

    



    

    return 0;
}
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
    print("Please type a word bank file and press Enter to select which file to use as a word bank, or press \"Enter\" to use the default.");
    std::getline(std::cin, file);

    // for if its default
    if (file == "")
    {
        file = "allWords.txt";
    }



    // loops until you get a valid file
    std::ifstream inputFile(file);
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
    // std::cout << "DEBUG: should be 1000: " << allWords.size() << std::endl;
    // for (std::string::size_type i = 0; i < allWords.size(); i++)
    // {
    //     print(allWords[i]);
    // }


    // the input that will be spell checked
    std::string textInput;
    
    // vector of strings that will hold all the words from the input
    std::vector<std::string> words;

    // transferring the input to a vector of words
    print("Type a text entry that you want to be spell checked and press enter.");
    std::getline(std::cin, textInput);
    inputToVector(textInput, words);
    print();
    

    // print("DEBUG: all of the words");
    // printVector(words);

    // std::getline(std::cin, textInput);

    std::string numInput;
    for (std::string::size_type i = 0; i < words.size(); ++i)
    {
        // std::cout << "DEBUG: should be current word suggestion: " << words[i] << std::endl;
        // std::getline(std::cin, textInput);
        if (!wordBank.contains(words[i]))
        {
            std::vector<std::string> suggestions(findSuggestions(words[i], wordBank));
            if (suggestions.size() > 0)
            {
                print();
                std::cout << "By \"" << words[i] << "\", do you mean..." << std::endl;
                for (std::string::size_type i = 0; i < suggestions.size(); ++i)
                {
                    std::cout << i+1 << ": " << suggestions[i] << "?" << std::endl;
                }
                print("Type the number of the correctly spelled word and press enter to change it.");
                print("Otherwise just press enter to skip.");
                while (true)
                {
                    std::getline(std::cin, numInput);
                    try
                    {
                        if (numInput == "")
                        {
                            break;
                        }
                        else
                        {
                            int inputCorrection = std::stoi(numInput) - 1;
                            if (inputCorrection >= 0 && inputCorrection < (int) suggestions.size())
                            {
                                words[i] = suggestions[inputCorrection];
                                numInput = "";
                                break;
                            }
                            print();
                            print("Not a valid input. Please try again.");
                        }
                        
                    }
                    catch(const std::exception& e)
                    {
                        print();
                        print("Not a valid input. Please try again.");
                    }
                    
                }
                
            }
        }
        
    }
    
    // printing the new sentence:
    print();
    print();
    print("This is your spell corrected text entry:");
    print();
    for (std::string::size_type i = 0; i < words.size(); ++i)
    {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
    print();
    print("Press enter to continue.");
    std::getline(std::cin, numInput);

    



    

    return 0;
}
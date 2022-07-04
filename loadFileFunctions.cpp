#include "loadFileFunctions.hpp"

void loadAllWords(std::ifstream& inputFile, hashSet& h)
{
    std::string loadString;
    while (std::getline(inputFile, loadString))
    {
        h.add(loadString);
    }
}

void inputToVector(std::string line, std::vector<std::string>& words)
{
    // this will hold the word that got split from the line
    std::string word;

    // this creates the string stream from the line
    std::istringstream iss(line);

    while (std::getline(iss, word, ' '))
    {
        words.push_back(word);
    }
}
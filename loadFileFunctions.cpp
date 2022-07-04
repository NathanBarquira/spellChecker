#include "loadFileFunctions.hpp"

void loadAllWords(std::ifstream& inputFile, hashSet& h)
{
    std::string loadString;
    while (std::getline(inputFile, loadString))
    {
        h.add(loadString);
    }
}
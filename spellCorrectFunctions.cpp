#include "spellCorrectFunctions.hpp"


std::vector<std::string> findSuggestions(const std::string& word, const hashSet& wordBank) 
{
    // vector of possible correct spellings
    std::vector<std::string> suggestions;

    // these are all the techniques to suggest possible misspellings
    wrongOrdering(word, suggestions, wordBank);    
    missingLetter(word, suggestions, wordBank);  
    additionalLetter(word, suggestions, wordBank);
    differentLetter(word, suggestions, wordBank);
    noSpace(word, suggestions, wordBank);

    return suggestions;
}

bool notIn(const std::string& word, const std::vector<std::string>& suggestions)
{
    print("DEBUG: inside not in function");
    for (std::string::size_type i = 0; i < suggestions.size(); ++i)
    {
        if (suggestions[i] == word)
        {
            return false;
        }
    }
    return true;
}

void wrongOrdering(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank)
{
    print("DEBUG: inside wrongOrdering function");
    std::string temp(word);

    // this will be for swapping each pair of characters in the word
    for (std::string::size_type i = 0; i < word.size() - 1; ++i)
    {
        std::swap(temp[i], temp[i+1]);
        if (wordBank.contains(temp) && notIn(temp, suggestions))
        {
            suggestions.push_back(temp);
        }
        std::swap(temp[i], temp[i+1]);
    }
}

void missingLetter(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank)
{
    print("DEBUG: inside missingLetter function");
    // string that contains the alphabet in capitals
    std::string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    for (std::string::size_type i = 0; i < word.size(); ++i)
    {
        std::string part1(word.substr(0, i));
        std::string part2(word.substr(i));

        for (std::string::size_type j = 0; j < alphabet.size(); ++j)
        {   
            std::string temp(part1 + alphabet[j] + part2);
            if (wordBank.contains(temp) && notIn(temp, suggestions))
            {
                suggestions.push_back(temp);
            }
        }
    }

    // this is for the adding an alphabet to the end of the word
    for (std::string::size_type j = 0; j < alphabet.size(); ++j)
        {   
            std::string temp(word + alphabet[j]);
            if (wordBank.contains(temp) && notIn(temp, suggestions))
            {
                suggestions.push_back(temp);
            }
        }
}

void additionalLetter(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank)
{
    print("DEBUG: inside additionLetter function");
    for (std::string::size_type i = 0; i < word.size(); ++i)
    {
        std::string part1(word.substr(0, i));
        std::string part2(word.substr(i+1));
        
        std::string temp(part1 + part2);
        std::cout << "DEBUG: should be temp: " << temp << std::endl;
        if (wordBank.contains(temp) && notIn(temp, suggestions))
        {
            suggestions.push_back(temp);
        }
        
    }
}

void differentLetter(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank) 
{
    print("DEBUG: inside differentLetter function");
    // string that contains the alphabet in capitals
    std::string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    std::string temp(word);

    for (std::string::size_type i = 0; i < alphabet.size(); ++i)
    {
        for (std::string::size_type j = 0; j < word.size(); ++j)
        {
            std::swap(temp[j], alphabet[i]);
            if (wordBank.contains(temp) && notIn(temp, suggestions))
            {
                suggestions.push_back(temp);
            }
            std::swap(temp[j], alphabet[i]);
        }
    }
}

void noSpace(const std::string& word, std::vector<std::string>& suggestions, const hashSet& wordBank) 
{
    print("DEBUG: inside noSpace function");
    for (std::string::size_type i = 0; i < word.size(); ++i)
    {
        std::string part1(word.substr(0, i));
        std::string part2(word.substr(i));
        std::string temp(part1 + " " + part2);
        if (wordBank.contains(part1) && wordBank.contains(part2) && notIn(temp, suggestions))
        {
            suggestions.push_back(temp);
        }
    }
}
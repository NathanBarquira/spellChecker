#include "helperFunctions.hpp"

// this is all the definitions:

void print(const char * text)
{
    std::cout << text << std::endl;
}

void print(std::string text)
{
    std::cout << text << std::endl;
}

std::string random_string()
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 32);    // assumes 32 < number of characters in str         
}

void printVector(const std::vector<std::string> & v)
{
    for (std::string::size_type i = 0; i < v.size(); ++i)
    {
        print(v[i]);
    }
}

#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include <iostream>
#include <string>

// this is all the declarations:

// basic print function
void print(const char * text = "");

// basic print function with template
// template <typename T>
// void print(T text);


// this is all the definitions:

void print(const char * text)
{
    std::cout << text << std::endl;
}

// template <typename T>
// void print(T text)
// {
//     std::cout << text << std::endl;
// }

#endif
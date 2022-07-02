#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include <iostream>
#include <string>

// this is all the declarations:

// basic print function
template <typename T>
void print(T text = "");


// this is all the definitions:

template <typename T>
void print(T text)
{
    std::cout << text << std::endl;
}

#endif
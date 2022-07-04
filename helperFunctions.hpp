#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include <random>
#include <iostream>
#include <string>
#include <algorithm>

// this is all the declarations:

// basic print function const char
void print(const char * text = "");

// basic print function
void print(std::string text);

// generates a random string (borrowed from stack overflow!)
std::string random_string();

#endif
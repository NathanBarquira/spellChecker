#include "hashFunctions.hpp"

int hashPaulLarson(std::string s)
{
    const char * c = s.c_str();
    int h = 0;
    while (*c)
        h = h * 101 + (int) *c++;
    return h;
}
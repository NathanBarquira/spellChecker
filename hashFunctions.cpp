#include "hashFunctions.hpp"

unsigned hashPaulLarson(std::string s)
{
    unsigned h = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        h = h * 101 + (unsigned) s[i + 1];
    }

    return h;
}
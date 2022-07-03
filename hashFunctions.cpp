#include "hashFunctions.hpp"

int hashPaulLarson(std::string s)
{
    int h = 0;
    for (std::string::size_type i = 0; i < s.size()-1; ++i)
    {
        h = h * 101 + (int) s[i + 1];
    }

    return h;
}
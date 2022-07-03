#include "hashFunctions.hpp"

unsigned hashPaulLarson(const char* s, unsigned salt)
{
    unsigned h = salt;
    while (*s)
        h = h * 101 + (unsigned) *s++;
    return h;
}
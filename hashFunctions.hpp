#ifndef HASHFUNCTIONS_HPP
#define HASHFUNCTIONS_HPP

#include <string>

// This will hold all the hash functions that could be used.
// Can be studied to see which one performs the best.

// This is the Microsoft Research Paul Larson's hash function
// The original function has a "salt" parameter meant to dissuade
// hash comprimising, but security isn't important here so we initialize
// it to be 0.
unsigned hashPaulLarson(std::string s);

#endif
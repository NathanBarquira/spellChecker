#ifndef HASHSET_HPP
#define HASHSET_HPP

#include <iostream>

// Notes:
// * I am assuming I can translate everything into a std::string, so I will not be using
// a template for this.

class hashSet
{
    // default constructor for hashSet
    explicit hashSet();

    // copy constructor for hashSet
    hashSet(const hashSet& s);

    // destructor for hashSet
    ~hashSet();
};

#endif
#ifndef HASHSET_HPP
#define HASHSET_HPP

#include <iostream>
#include "helperFunctions.hpp"

// Notes:
// * I am assuming I can translate everything into a std::string, so I will not be using
// a template for this.
// * the hashTable method I will be using is seperate chaining (dynamic array of dynamic linked lists)

class hashSet
{

public:
    // default constructor for hashSet
    explicit hashSet();

    // copy constructor for hashSet
    hashSet(const hashSet& s);

    // destructor for hashSet
    ~hashSet();

private:
    // member variables:

};

#endif
#ifndef HASHSET_HPP
#define HASHSET_HPP

#include <iostream>
#include "helperFunctions.hpp"
#include "hashFunctions.hpp"
#include "linkedList.hpp"
#include <vector>

// Notes:
// * I am assuming I can translate everything into a std::string, so I will not be using
// a template for this.
// * the hashTable method I will be using is seperate chaining (dynamic array of dynamic linked lists)
// * default size will be 10
// * once size of set is bigger than 0.7 of its capacity, we will rehash everything

// TODO:

class hashSet
{

public:
    // default constructor for hashSet
    explicit hashSet();

    // copy constructor for hashSet
    hashSet(const hashSet& s);

    // adding a string into the hashSet
    void add(std::string word);

    // bool checking to see if a word is inside the set
    bool contains(std::string word) const;

    // returns the number of elements in the set
    int sizeCount();

    // returns the capacity of the array
    int capacityCount();

    // prints all the elements in the set
    void printAll();

    // returns a vector with all words in the set (mainly for debugging)
    std::vector<std::string> allToVector();

    // removes a string from the hashSet
    void remove(std::string word);

    // destructor for hashSet
    ~hashSet();

private:
    // the array of linkedLists per seperate chaining method of hash function
    linkedList* hashArray;

    // the capacity of the array
    int capacity = 10;

    // the number of elements in the set
    int size = 0;
};



#endif
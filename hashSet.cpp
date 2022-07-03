#include "hashSet.hpp"

hashSet::hashSet()
    : hashArray(new linkedList[10])
{
    print("DEBUG: inside hashSet constructor");
}

void hashSet::add(std::string word)
{
    print("DEBUG: inside the add function");

    // this hashes the word and puts it in the right spot
    int hash = hashPaulLarson(word);
    int hashIndex = hash % capacity;
    std::cout << "DEBUG: should be hash value: " << hash << std::endl;
    std::cout << "DEBUG: should be hashIndex: " << hashIndex << std::endl;

    // testing to see if that word already exists
    if (hashArray[hashIndex].contains(word) == false)
    {
        std::cout << "DEBUG: word is not contained" << std::endl;
        hashArray[hashIndex].addNode(word);
        size += 1;
        std::cout << "DEBUG: should be size: " << size << std::endl;

        // checking if should rehash
        if (size >= 0.7 * capacity)
        {
            print("DEBUG: rehashing process");
            // doubling the capacity and resetting the size
            capacity = capacity * 2;
            size = 0;

            // rehashing
            linkedList * oldHashArray = hashArray;
            hashArray = new linkedList[capacity];
            for (int i = 0; i < capacity / 2; ++i)
            {
                node * currentPointer = oldHashArray[i].head;
                while (currentPointer != nullptr)
                {
                    add(currentPointer->info);
                    currentPointer = currentPointer->next;
                }
            }
        }
    }
    else
    {
        print("DEBUG: cannot add same value since it is a set");
    }
}

hashSet::~hashSet()
{
    print("DEBUG: inside hashSet destructor");
}
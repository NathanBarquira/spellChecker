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
    int hashIndex = hashPaulLarson(word) % capacity;

    // testing to see if that word already exists
    if (hashArray[hashIndex].contains(word) == false)
    {
        hashArray[hashIndex].addNode(word);
        size += 1;

        // checking if should rehash
        if (size >= 0.7 * capacity)
        {
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
}

hashSet::~hashSet()
{
    print("DEBUG: inside hashSet destructor");
}
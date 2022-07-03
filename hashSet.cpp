#include "hashSet.hpp"

hashSet::hashSet()
    : hashArray(new linkedList[10])
{
    print("DEBUG: inside hashSet constructor");
}

hashSet::~hashSet()
{
    print("DEBUG: inside hashSet destructor");
}
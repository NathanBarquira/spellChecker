#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

// notes:
// * assuming everything is going to be using strings

struct node
{
    // default constructor for node class
    node();

private:
    std::string info;
    node * next;
};

class linkedList
{
public:
    
    // default constructor for linkedList class
    linkedList();

    // copy constructor for linkedList class
    linkedList(const linkedList& l);

    // destructor for linkedList class
    ~linkedList();

private:

};

#endif
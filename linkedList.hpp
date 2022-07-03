#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

// notes:
// * assuming everything is going to be using strings

struct node
{
    // default constructor for node class
    node(std::string info, node * nextNode = nullptr);

    // the std::string info the node contains
    std::string info;

    // the next pointer
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

    // adding a node to the linkedlist
    void add(std::string info);

    // print the current linkedList
    void printList();

private:
    // the first node (or nullptr) to the linkedlist
    node * head;
};

#endif
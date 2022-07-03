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

    // move constructor for linkedlist class
    linkedList(linkedList&& l);

    // assignment operator
    linkedList& operator=(const linkedList& l);

    // destructor for linkedList class
    ~linkedList();

    // adding a node to the linkedlist
    void addNode(std::string info);

    // deleting a node in the linkedlist
    void deleteNode();

    // print the current linkedList
    void printList();

    // bool that tells if the string is inside the list
    bool contains(std::string word);

    // the first node (or nullptr) to the linkedlist
    node * head;


private:
    // deletes the entire list
    void deleteList();
};

#endif
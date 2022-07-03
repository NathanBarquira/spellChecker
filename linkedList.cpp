#include "linkedList.hpp"
#include "helperFunctions.hpp"

node::node(std::string info, node * nextNode)
    : info(info), next(nextNode)
{
    print("DEBUG: inside node class default constructor");
}

linkedList::linkedList()
    : head(nullptr)
{
    print("DEBUG: inside default constructor for linkedlist");
    // std::cout << "DEBUG: inside default linkedlist constructor " << std::endl;
}

linkedList::~linkedList()
{
    print("DEBUG: inside destructor for linkedlist");
}
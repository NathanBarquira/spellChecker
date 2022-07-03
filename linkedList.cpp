#include "linkedList.hpp"
#include "helperFunctions.hpp"

node::node(std::string info, node * nextNode)
    : info(info), next(nextNode)
{
    print("DEBUG: inside node class default constructor");
    std::cout << "DEBUG: value added = " << info << std::endl;
}

linkedList::linkedList()
    : head(nullptr)
{
    print("DEBUG: inside default constructor for linkedlist");
}

void linkedList::add(std::string info)
{
    print("DEBUG: inside add function linked list");
    node * newNode = new node(info, head);
    head = newNode;
}

void linkedList::printList()
{
    print("DEBUG: inside the printList function");
    node * temp_head = head;
    while (temp_head != nullptr)
    {
        print(temp_head->info);
        temp_head = temp_head->next;
    }
}

linkedList::~linkedList()
{
    print("DEBUG: inside destructor for linkedlist");
}
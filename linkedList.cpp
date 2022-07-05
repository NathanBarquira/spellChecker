#include "linkedList.hpp"
#include "helperFunctions.hpp"

node::node(std::string info, node * nextNode)
    : info(info), next(nextNode)
{
    // print("DEBUG: inside node class default constructor");
    // std::cout << "DEBUG: value added = " << info << std::endl;
}

linkedList::linkedList()
    : head(nullptr)
{
    // print("DEBUG: inside default constructor for linkedlist");
}

linkedList::linkedList(const linkedList& l)
    : head(nullptr)
{
    node * temp_head = l.head;

    if (temp_head != nullptr)
    {
        // print("DEBUG: not copying from empty linkedlist");
        addNode(temp_head->info);
        node * back_head = head;
        temp_head = temp_head->next;
        while (temp_head != nullptr)
        {
            // print("DEBUG: length is more than one");
            node * add_head = new node(temp_head->info);
            back_head->next = add_head;
            back_head = add_head;
            temp_head = temp_head->next;
        }
    }
}

linkedList::linkedList(linkedList&& l)
    : head(nullptr)
{
    // print("DEBUG: inside linked list move constructor");
    std::swap(l.head, head);
}

linkedList& linkedList::operator=(const linkedList& l)
{
    // print("DEBUG: inside assignment operator");

    // note this is to catch a possible exception
    node * headBackup = head;
    node * newHead;
    try
    {
        node * temp_head = l.head;
        if (temp_head != nullptr)
        {
            // print("DEBUG: not copying from empty linkedlist");
            newHead = new node(temp_head->info);
            node * back_head = newHead;
            temp_head = temp_head->next;
            while (temp_head != nullptr)
            {
                // print("DEBUG: length is more than one");
                node * add_head = new node(temp_head->info);
                back_head->next = add_head;
                back_head = add_head;
                temp_head = temp_head->next;
            }
            deleteList();
            head = newHead;
        }
    }
    catch(const std::exception& e)
    {
        while (newHead != nullptr)
        {
            node * deleteHead = newHead;
            newHead = newHead->next;
            delete deleteHead;
        }
        head = headBackup;
    }
    
    return *this;
}

void linkedList::addNode(std::string info)
{
    // print("DEBUG: inside add function linked list");
    node * newNode = new node(info, head);
    head = newNode;
}

void linkedList::deleteNode()
{
    // print("DEBUG: inside delete head linked list");
    node * deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void linkedList::printList()
{
    // print("DEBUG: inside the printList function");
    node * temp_head = head;
    while (temp_head != nullptr)
    {
        print(temp_head->info);
        temp_head = temp_head->next;
    }
}

bool linkedList::contains(std::string word)
{
    // print("DEBUG: inside contains method");
    node * tempHead = head;
    while (tempHead != nullptr)
    {
        if (tempHead->info == word)
        {
            return true;
        }
        tempHead = tempHead->next;
    }
    return false;
}

void linkedList::deleteNode(std::string word)
{
    // print("DEBUG: inside delete method");
    
    // can't delete anything if the head is a nullptr
    if (head == nullptr)
    {
        return;
    }

    // for dealing with deleting the first node in the linkedlist
    node * tempHead = head;
    if (tempHead->info == word)
    {
        // std::cout << "DEBUG: found the word! " << std::endl;
        head = tempHead->next;
        delete tempHead;
        return;
    }
    
    // for dealing with else
    node * prevHead = tempHead;
    tempHead = tempHead->next;
    while (tempHead != nullptr)
    {
        // std::cout << "DEBUG: tempHead->info: " << tempHead->info << std::endl;
        // std::cout << "DEBUG: prevHead->info: " << prevHead->info << std::endl;
        if (tempHead->info == word)
        {
            // std::cout << "DEBUG: found the word! " << std::endl;
            prevHead->next = tempHead->next;
            delete tempHead;
            break;
        }
        prevHead = tempHead;
        tempHead = tempHead->next;
    }
}

void linkedList::deleteList()
{
    while (head != nullptr)
    {
        deleteNode();
    }
}

linkedList::~linkedList()
{
    // print("DEBUG: inside destructor for linkedlist");
    deleteList();
}
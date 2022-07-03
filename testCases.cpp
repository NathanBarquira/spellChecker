#include "helperFunctions.hpp"
#include "linkedList.hpp"

int main()
{
    print();
    print("This is the test cases for the program: ");

    print();
    print("Testing linkedlist class constructor: ");
    linkedList L;

    print();
    print("Testing linkedlist add");
    L.addNode("world!");
    L.addNode("Hello");

    print();
    print("Testing print function");
    L.printList();

    print("testing linkedlist delete");
    L.deleteNode();
    L.printList();

    print("testing copy constructor");
    L.addNode("Hello");
    linkedList L2(L);
    L.printList();
    L2.printList();

    print("testing move constructor");
    linkedList L3(std::move(L2));
    print("L2 print list (should be empty)");
    L2.printList();
    print("L3 print list (should not be empty)");
    L3.printList();

    print("testing copy constructor");
    L2 = L3;
    print("L2 print list (should not be empty)");
    L2.printList();
    print("L3 print list (should not be empty)");
    L3.printList();

    print();

    return 0;
}
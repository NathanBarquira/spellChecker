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
    L.add("world!");
    L.add("Hello");

    print();
    print("Testing print function");
    L.printList();

    print();

    return 0;
}
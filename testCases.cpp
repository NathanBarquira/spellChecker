#include "helperFunctions.hpp"
#include "linkedList.hpp"
#include "hashSet.hpp"

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

    print();
    print("testing linkedlist delete");
    L.deleteNode();
    L.printList();

    print();
    print("testing copy constructor");
    L.addNode("Hello");
    linkedList L2(L);
    L.printList();
    L2.printList();

    print();
    print("testing move constructor");
    linkedList L3(std::move(L2));
    print("L2 print list (should be empty)");
    L2.printList();
    print("L3 print list (should not be empty)");
    L3.printList();

    print();
    print("testing copy constructor");
    L2 = L3;
    print("L2 print list (should not be empty)");
    L2.printList();
    print("L3 print list (should not be empty)");
    L3.printList();

    print();
    print("testing delete method");
    L2.printList();
    L2.deleteNode("Hello");
    L2.printList();
    L2.deleteNode("world!");
    L2.printList();
    L2.deleteNode("hi!");
    L2.printList();

    print();
    print("testing hashSet constructor");
    hashSet H;

    print();
    print("testing hashSet add");
    H.add("how");
    H.add("how");
    H.add("are");
    H.add("you");
    H.add("doing");
    H.add("today");
    H.add("my");
    H.add("name");

    print();
    print("testing hashSet contains method");
    std::cout << "should be 1 (true): " << H.contains("how") << std::endl;
    std::cout << "should be 1 (true): " << H.contains("my") << std::endl;
    std::cout << "should be 0 (false): " << H.contains("elephant") << std::endl;
    std::cout << "should be 0 (false): " << H.contains("baby") << std::endl;

    print();
    print("testing sizeCount method");
    std::cout << "should be 7: " << H.sizeCount() << std::endl;

    print();
    print("testing capacityCount method");
    std::cout << "should be 20: " << H.capacityCount() << std::endl;

    print();
    print("testing print all method");
    H.printAll();

    print();
    print("testing remove method");
    std::cout << "DEBUG: should be 1 (true): " << H.contains("name") << std::endl;
    H.remove("name");
    std::cout << "DEBUG: should be 0 (false): " << H.contains("name") << std::endl;

    print();
    print("big test");
    hashSet test;
    for (int i = 0; i < 100; ++i)
    {
        test.add(random_string());
    }
    test.printAll();

    print();

    return 0;
}
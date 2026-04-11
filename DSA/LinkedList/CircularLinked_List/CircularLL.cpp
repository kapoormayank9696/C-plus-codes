// All Operation Are Apply In Circular Linked List Algorithms Implementation In C++
#include <iostream>
using namespace std;

// Node class of Circular Linked List
class Node {
    // Public Access Specifier
    public:   
    // Data Members
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};



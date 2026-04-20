// Sorting A Singly Linked List Implementation In C++
#include <iostream>
using namespace std;
// Node class of the singly linked list
class Node {
    // Public Access Specifier
    public:   
    // Data members of the Node class
    int data;
    Node* next;
    // Parameterized Constructor
    Node(int value){
        this->data = value;
        this->next = nullptr;
    }

    Node* head=nullptr;

    // Function to insert a new node at the end of the linked list
    void insert(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to sort the linked list using Bubble Sort algorithm
    void bubbleSort(){
        if(head == nullptr){
            return;
        }
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    // Function to print the linked list
    void printList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



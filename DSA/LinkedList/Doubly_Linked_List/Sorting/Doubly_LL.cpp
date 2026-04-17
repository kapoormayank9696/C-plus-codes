// Doubly Linked List Sorting Algorithm Implementation in C++
#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
class Node {
    // Public Access Specifier
    public:
    // Data Members
    int data;
    Node* next;
    Node* prev;
    // Parameterized Constructor
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    // Public Access Specifier
    public:
    Node* head=nullptr;
    // Function to insert node in the doubly linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
        }else {
            Node* temp=head;
            while(temp -> next != nullptr) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->prev=temp;
        }
    }

    // Function to display the doubly linked list
    void display() {
        if(head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp=head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }

    // Function to sort the doubly linked list using Bubble Sort
    void bubbleSort() {
        if(head == nullptr) {
            return;
        }
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = head;
            while(ptr1->next != nullptr && ptr1->next != lptr){
                if(ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while(swapped);
    }
};

// Main function
int main() {
    DoublyLinkedList dll;
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        dll.insert(data);
    }
    cout << "Original List: ";
    dll.display();
    dll.bubbleSort();
    cout << "Sorted List: ";
    dll.display();
    return 0;
}


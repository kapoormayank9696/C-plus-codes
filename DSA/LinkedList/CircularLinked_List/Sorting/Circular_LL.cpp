// Circular Linked List Sorting Algorithm Implementation in C++
#include <iostream>
using namespace std;
// Node structure for Circular Linked List
class Node {
    // Public Access Specifier
    public:
    // Data Members
    int data;
    Node* next;
    // Parameterized Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
    // Public Access Specifier
    public:
    Node* head=nullptr;
    // Function to insert node in the circular linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            newNode->next=head;
        }else {
            Node* temp=head;
            while(temp -> next != head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    // Function to display the circular linked list
    void display() {
        if(head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp=head;
        do {
            cout << temp->data << " ";
            temp=temp->next;
        } while(temp != head);
        cout << endl;
    }

    // Function to sort the circular linked list using Bubble Sort
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
            while(ptr1 -> next != head && ptr1->next != lptr) {
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
    CircularLinkedList cll;
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        cll.insert(data);
    }
    cout << "Original List: ";
    cll.display();
    cll.bubbleSort();
    cout << "Sorted List: ";
    cll.display();
    return 0;
}

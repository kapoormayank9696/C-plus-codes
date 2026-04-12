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
    public:
    Node* head = nullptr;  
    // Insert Node In Circular Linked List
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head->next=newNode;
            head=newNode;
        } else {
            Node* temp=head;
            while(temp->next!=head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    // Insert Node at beginning of Circular Linked List
    void insertAtBeginning(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head->next=newNode;
            head=newNode;
        } else {
            Node* temp=head;
            while(temp->next!=head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
            head=newNode;
        }
    }

    // Insert Node at position of Circular Linked List
    void insertAtPosition(int data, int position) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head->next=newNode;
            head=newNode;
        } else {
            if(position == 1) {
                insertAtBeginning(data);
                return;
            }
            Node* temp=head;
            int count=1;
            while(count<position-1 && temp->next!=head) {
                temp=temp->next;
                count++;
            }
            if(temp->next==head) {
                insertAtEnd(data);
                return;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    
    // Insert Node at end of Circular Linked List
    void insertAtEnd(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head->next=newNode;
            head=newNode;
        } else {
            Node* temp=head;
            while(temp->next!=head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    // Display Circular Linked List
    void display() {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        Node* temp=head;
        do {
            cout<<temp->data<<" ";
            temp=temp->next;
        } while(temp!=head);
        cout<<"(head)"<<endl;
    }
};

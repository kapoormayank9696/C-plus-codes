// Searching In Doubly Linked List Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Class for doubly linked list
class DoublyLL {
    // Public Access Modifier
    public:
    // Node class of doubly linked list
    class Node {
        // Public Access Modifier
        public:
        // Data Members
        int data;
        Node* next;
        Node* prev;
        // Parameterized Constructor
        Node(int data) {
            this->data=data;
            this->next=nullptr;
            this->prev=nullptr;
        }
    };

    Node* head=nullptr;
    Node* tail=nullptr;

    // Method to insert the nodes into doubly linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=tail=newNode;
            return;
        }
        else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    // Method of searching in doubly linked list
    bool search(int value) {
        if(head == nullptr) {
            return false;
        }
        Node* temp=head;
        while(temp != nullptr) {
            if(temp->data == value) {
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    // Method to display the doubly linked list
    void display() {
        if(head == nullptr) {
            cout<<"Empty Doubly Linked List....."<<endl;
            return;
        }
        Node* temp=head;
        while(temp != nullptr) {
            cout<<temp->data<<" <--> ";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }

    // Destructor for prevents to memory leaks,Correctly deletes doubly structure,Handles all cases safely
    ~DoublyLL() {
        Node* temp = head;
        while(temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLL list;
    cout<<"Enter number of terms: ";
    int n,values;
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list.insert(values);
    }
    cout<<"Display the doubly linked list: ";
    list.display();
    cout<<"Enter node for searching: ";
    cin>>values;
    if(list.search(values)) {
        cout<<"Yes, the node exists in the doubly linked list."<<endl;
    }else {
        cout<<"No, the node is not exist in the doubly linked list...."<<endl;
    }
    return 0;
}

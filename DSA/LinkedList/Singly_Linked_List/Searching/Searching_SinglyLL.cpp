// Searching In Singly Linked List Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Class for singly linked list
class SinglyLL {
    // Public Access Modifier
    public:
    // Node class of singly linked list
    class Node {
        // Public Access Modifier
        public:
        // Data Members
        int data;
        Node* next;
        // Parameterized Constructor
        Node(int data) {
            this->data=data;
            this->next=nullptr;
        }
    };

    Node* head=nullptr;

    // Method to insert the nodes into singly linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next != nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
    }

    // Method of searching in singly linked list
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

    // Method to display the singly linked list
    void display() {
        if(head == nullptr) {
            cout<<"Empty Singly Linked List....."<<endl;
            return;
        }
        Node* temp=head;
        while(temp != nullptr) {
            cout<<temp->data<<"--> ";
            temp=temp->next;
        }
        cout<<"END"<<endl;
    }

    // Destructor for prevents to memory leaks,Correctly deletes singly structure,Handles all cases safely
    ~SinglyLL() {
        Node* temp = head;
        while(temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    SinglyLL list;
    cout<<"Enter number of terms: ";
    int n,values;
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list.insert(values);
    }
    cout<<"Display the singly linked list: ";
    list.display();
    cout<<"Enter node for searching: ";
    cin>>values;
    if(list.search(values)) {
        cout<<"Yes, the node exists in the singly linked list."<<endl;
    }else {
        cout<<"No, the node does not exist in the singly linked list."<<endl;
    }
    return 0;
}

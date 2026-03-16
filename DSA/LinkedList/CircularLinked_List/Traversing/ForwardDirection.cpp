// Forward Traversing of Circular Linked List Algorithm Implmentation In C++
#include<iostream>
using namespace std;
// Class of Circular Linked List
class CircularLL{
    // Public Access Modifier
    public:
    // Node class of Circular Linked List
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
    
    // Function to insert the node into circular linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            newNode->next=head;
        }
        Node* temp=head;
        // Find head node
        while(temp->next != head) {
            temp=temp->next;
        }
        temp->next=newNode; // last node points to second node
        newNode->next=head; // Move head towards
    }

    // Function to forward traversal the circular linked list
    void forwardTraversal() {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List!!!!"<<endl;
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data<<"<-->";
            temp=temp->next;
        }while(temp != head);
        cout<<"(head)"<<endl;
    }

    // Function to display the circular linked list
    void display() {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List!!!!"<<endl;
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data<<"<-->";
            temp=temp->next;
        }while(temp != head);
        cout<<"(head)"<<endl;
    }
};

// Main function
int main() {
    CircularLL* list=new CircularLL();
    int n,values;
    cout<<"Enter number of sizes: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list->insert(values);
    }
    cout<<"Display The Circular Linked List: ";
    list->display();
    cout<<"Forward Traversal Of Circular Linked List: ";
    list->forwardTraversal();
    return 0;
}


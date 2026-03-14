// Delete The Node From End Circular Linked List Algorithm In C++
#include<iostream>
using namespace std;
// Class of Circular Linked List
class CircularLL {
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

    // Function to insert the nodes into circular linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            newNode->next=head;
            return;
        }
        Node* temp=head;
        while(temp->next != head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }

    // Function to delete the last node from circular linked list
    void deleteAtEnd() {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List!!!!";
            return;
        }
        // If only one node
        if(head->next == head) {
            head=nullptr;
            return;
        }
        Node* temp=head;
        while(temp->next->next != head) {
            temp=temp->next;
        }
        Node* last = temp->next; // last node
        // Remove last node from circular linked list
        temp->next=head; // update link
        delete last; // free memory
    }

    // Function to display the circular linked list
    void display() {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List!!!!"<<endl;
            return;
        }
        Node* temp=head;
        do {
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
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list->insert(values);
    }
    cout<<"Display The Circular Linked List: ";
    list->display();
    list->deleteAtEnd();
    cout<<"After delete the node from last circular linked list: ";
    list->display();
    return 0;
}


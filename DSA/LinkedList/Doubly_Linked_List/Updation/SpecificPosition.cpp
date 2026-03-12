// Update The Node From Specific Position Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Node class of Doubly Linked List
class Node {
    // Public Access Modifier
    public:
    int data;
    // Data Members
    Node* next;
    Node* prev;
    // Parameterized Constructor
    Node(int data) {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

// Doubly Linked List class
class DoublyLL{
    public:
    Node* head=nullptr;
    Node* tail=nullptr;
    
    // Function to insert the nodes in Doubly Linked List
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            tail=newNode;
        }else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }  

    // Function to update the node from specific position
    void updateAtSpecific(int index,int value) {
         if(head == nullptr) {
            cout<<"Doubly Linked List is empty. Cannot update."<<endl;
            return;
        }
        else if(index <= 0) {
            cout<<"Invalid Range of Specific Position!!!!"<<endl;
        } 
        else {
            Node* temp=head;
            int count=1;
            while(temp != nullptr) {
                if(count == index) {
                    temp->data=value;
                    return;
                }
                temp=temp->next;
                count++;
            }
        }
    }

    // Display the Doubly Linked List
    void display() {
        if(head == nullptr) {
            cout<<"Empty Doubly Linked List!!!!"<<endl;
            return;
        }
        Node* temp=head;
        while(temp != nullptr) {
            cout<<temp->data<<"<-->";
            temp=temp->next;
        }
        cout<<"null"<<endl;
    }
};

// Main function
int main() {
    DoublyLL* list=new DoublyLL();
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<"Enter nodes in Doubly Linked List: ";
    for(int i=0;i<n;i++) {
        int values;
        cin>>values;
        list->insert(values);
    }
    cout<<"Display Doubly Linked List nodes: ";
    list->display();
    int values,index;
    cout<<"Enter index: ";
    cin>>index;
    cout<<"Enter the value to update the node from Doubly Linked List: ";
    cin>>values;
    list->updateAtSpecific(index,values);
    cout<<"After update the node Doubly Linked List display: ";
    list->display();
    return 0;
}


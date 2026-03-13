// Insert The Node Into Circular Linked Linked List Algorithm Implementation In Java
#include<iostream>
using namespace std;
// Node Class Of Circular Linked List
class CircularLL{
    public:
    class Node {
        // Public Access Modifier
        public:
        int data;
        Node* next;
        // Data Members
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
        }else {
            Node* temp=head;
            while(temp->next != head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }
    
    // Function to insert the node at beginning position of circular linked list
    void insertAtBeginning(int value) {
        Node* newNode=new Node(value);
        if(head == nullptr) {
            head=newNode;
            // Pointing to itself as it's the only node in the list
            newNode->next=head;
        }
        Node* temp = head;
        // Find last node
        while(temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
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
        } while(temp != head);
        cout<<"(head)"<<endl;
    }
};


// Main function
int main() {
    CircularLL* list=new CircularLL();
    cout<<"Enter size of linked list: ";
    int n,values;
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list->insert(values);
    }
    cout<<"Print Circular Linked List: ";
    list->display();
    cout<<"Enter node value for insert at beginning position: ";
    cin>>values;
    list->insertAtBeginning(values);
    cout<<"After inserting the node at beginning in circular linked list: ";
    list->display();
    return 0;
}


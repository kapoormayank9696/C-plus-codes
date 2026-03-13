// Insert Node At End Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Class of Circular linked List
class CircularLL {
    public:
    // Node class of Circular Linked List
    class Node {
        public:
        int data;
        Node* next;
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
            // Pointing to itself as it's the only node in the list
            newNode->next=head;
        }
        Node* temp=head;
        while(temp->next != head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }

    // Function to insert the node at end of circular linked list
    void insertAtEnd(int data){
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            newNode->next=head; // Point to itself
            return;
        }
        Node* temp=head;
        while(temp->next != head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }

    // Function to display the circular linked list nodes
    void display() {
        if(head == nullptr) {
            cout<<"Empty Circluar linked List...."<<endl;
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
    cout<<"Enter node value for insert at end position: ";
    cin>>values;
    list->insertAtEnd(values);
    cout<<"After inserting the node at end in circular linked list:";
    list->display();
    return 0;
}

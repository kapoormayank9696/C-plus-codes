// Delete First node From Circular Linked List Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Class of Circular Linked List
class CircularLL {
    public:
    class Node {
        // Public Accesss Modifier
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

    // Function to insert the nodes in circular linked list
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
    
    // Function to delete first node from circular linked list
    void deleteAtBeginning() {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List!!!!"<<endl;
            return;
        }
        if(head->next == nullptr) {
            head=nullptr;
            return;
        }
        Node* temp=head;
        // Find head node
        while(temp->next != head) {
            temp=temp->next;
        }
        temp->next=head->next; // last node points to second node
        head=head->next; // Move head towards
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
    CircularLL* list =new CircularLL();
    int n,values;
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list->insert(values);
    }
    cout<<"Print the Circular Linked List: ";
    list->display();
    list->deleteAtBeginning();
    cout<<"Print the Circular Linked List after delete first node: ";
    list->display();
    return 0;
}


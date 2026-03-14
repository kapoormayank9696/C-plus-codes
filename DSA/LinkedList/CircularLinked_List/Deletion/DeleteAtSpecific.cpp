// Delete Specific node From Circular Linked List Algorithm Implementation In C++
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
    void deleteAtSpecific(int index) {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List!!!!"<<endl;
            return;
        } if(index <= 0) {
            cout<<"Invalid index!!!!"<<endl;
            return;
        }
        // Case 1: Delete first node
        if(index == 1) {
            if(head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* last = head;
            while(last->next != head) {
                last = last->next;
            }
            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }
        // Case 2: Delete node at given position
        Node* temp = head;
        int count = 1;
        while(count < index-1 && temp->next != head) {
            temp = temp->next;
            count++;
        } 
        if(temp->next == head) {
            cout<<"Index out of range!!!!"<<endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
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
    cout<<"Display The Circular Linked List: ";
    list->display();
    int index;
    cout<<"Enter index for deletion the node: ";
    cin>>index;
    list->deleteAtSpecific(index);
    cout<<"Print the Circular Linked List after delete specific position of node: ";
    list->display();
    return 0;
}


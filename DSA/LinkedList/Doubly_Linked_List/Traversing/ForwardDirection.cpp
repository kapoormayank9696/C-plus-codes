// C++ demonstrate traversal in forward direction doubly linked list
#include<iostream>
using namespace std;

// Node class to represent each element in the Doubly Linked List
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLL{
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    public:

    // Insert in doubly linked list
    void insert(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // Traverse in forward direction
    void ForwardDirection(){
        if(head == nullptr){
            cout<<"Empty Doubly Linked List"<<endl;
        }else{
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"<--->";
                temp = temp->next;
            }
            cout<<"null"<<endl;
        }
    }
     // Display Doubly Linked List
     void display(){
        if(head == nullptr){
            cout<<"Empty Doubly Linked List"<<endl;
        }else{
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"<--->";
                temp = temp->next;
            }
            cout<<"null"<<endl;
        }
    }
};

// Main function
int main(){
    DoublyLL* list=new DoublyLL();
    list->insert(2);
    list->insert(0);
    list->insert(19);
    list->insert(14);
    list->insert(34);
    cout<<"Doubly Linked List : ";
    list->display();
    // Insert at beginning
    cout<<"Traversing In Forward Direction: ";
    list->ForwardDirection();
    return 0;
}

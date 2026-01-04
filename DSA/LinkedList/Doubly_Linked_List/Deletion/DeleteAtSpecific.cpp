// C++ demonstration of deletion at the beginning of a doubly linked list
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
    // Delete at specific position
    void DeleteAtSpecific(int index){
        if(head==nullptr){
            cout<<"Empty Doubly Linked List!!"<<endl;
        }else{
            Node* temp=head;
            int count=1;
            while(temp!=nullptr){
                if(count==index){
                    temp->next=temp->next->next;
                    return;
                }
                temp=temp->next;
                count++;
            }
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
    // Delete at specific position
    cout<<"After deleting at specific position: ";
    list->DeleteAtSpecific(3);
    list->display();
    return 0;
}


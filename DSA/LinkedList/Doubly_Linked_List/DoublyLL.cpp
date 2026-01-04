// Doubly Linked List Implementation in C++
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

    // Insert at beginning
    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    // Insert at end
    void insertAtEnd(int data){
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

    // Insert at specific position
    void insertAtSpecific(int index,int data){
        Node* newNode=new Node(data);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            Node* temp=head;
            int count=1;
            while(temp!=nullptr){
                if(count==index){
                    newNode->next=temp->next;
                    temp->next=newNode;
                    return;
                }
                temp=temp->next;
                count++;
            }
        }
    }

    // Delete from beginning
    void deleteAtBeginning(){
        if(head==nullptr){
            cout<<"Empty Doubly Linked List!!"<<endl;
        }else{
            head=head->next;
        }
    }

    // Delete at end
    void deleteAtEnd(){
        if(head==nullptr){
            cout<<"Empty Doubly Linked List!!"<<endl;
        }else{
            Node* temp=head;
            while(temp->next!=nullptr){
                if(temp->next->next==nullptr){
                    temp->next=temp->next->next;
                    return;
                }
                temp=temp->next;
            }
        }
    }

    // Delete at specific position
    void deleteAtSpecific(int index){
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

    // Reverse the Doubly Linked List
    void reverse(){
        if(head==nullptr){
            cout<<"Empty Doubly Linked List"<<endl;
        }else{
            Node* current=head;
            Node*next=nullptr;
            Node* prev=nullptr;
            while(current!=nullptr){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            head=prev;
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

// Main function to test the Doubly Linked List
int main(){
    DoublyLL* list=new DoublyLL();
    list->insertAtEnd(2);
    list->insertAtEnd(0);
    list->insertAtEnd(19);
    list->insertAtEnd(14);
    cout<<"Doubly Linked List after inserting at end: ";
    list->display();

    cout<<"After inserting at beginning: ";
    list->insertAtBeginning(-5);
    list->display();

    cout<<"After inserting at specific position: ";
    list->insertAtSpecific(3,10);
    list->display();

    cout<<"After Deletion First Element: ";
    list->deleteAtBeginning();
    list->display();

    cout<<"After Deletion Last Element: ";
    list->deleteAtEnd();
    list->display();

    cout<<"After Deletion at specific position: ";
    list->deleteAtSpecific(2);
    list->display();

    cout<<"After reversing the Doubly Linked List: ";
    list->reverse();
    list->display();
    return 0;
}

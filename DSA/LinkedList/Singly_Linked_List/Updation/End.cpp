// Singly Linked List Implementation in C++
#include<iostream>
using namespace std;

// Node class to represent each element in the Linked List
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

// Singly Linked List class
class SinglyLL{
    public:
    Node* head = nullptr;
    public:
    
    //Insert Elements in Linked List
    void insert(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }temp->next = newNode;
        }
    }
    
    //Updating Linked List At End Position
    void UpdateAtEnd(int value){
        if(head == nullptr){
            cout<<"Empty Linked List........";
        }else{
            Node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->data=value;
        }
    }

    //Display Linked List
    void display(){
        if(head == nullptr){
            cout<<"Empty Linked List"<<endl;
        }else{
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"-->";
                temp = temp->next;
            }cout<<"null\n"<<endl;
        }
    }
};

// Main function to demonstrate the Singly Linked List 
int main(){
    SinglyLL* list=new SinglyLL();

    //Insert the elements in  Linked List
    cout<<"Insert elemets in the Linked List : ";
    list->insert(5);
    list->insert(10);
    list->insert(15);
    list->insert(20);
    list->insert(-5);
    list->insert(0);

    //Display the Linked List 
    list->display();
    
    //Updating At End position
    cout<<"After updating the Linked List : ";
    list->UpdateAtEnd(54);
    list->display();
    return 0;
}
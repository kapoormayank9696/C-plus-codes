#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class Remove{
    public:
    Node* head = nullptr;
    public:
    void insert(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void reverse(){
        if(head == nullptr){
            cout<<"Empty Linked List...........";
        }else{
            Node* next = nullptr;
            Node* current = head;
            Node* prev = nullptr;
            while(current != nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
    }
    void removeAtSpecific(int index){
        if(head == nullptr){
            cout<<"Empty Linked list............";
        }else{
            int count = 1;
            Node* temp = head;
            while(temp != nullptr){
                if(count == index-1){
                    temp->next = temp->next->next;
                }
                temp = temp->next;
                count++;
            }
        }
    }
    void display(){
        if(head == nullptr){
            cout<<"Empty Linked List..........";
        }else{
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"null"<<endl;
        }
    }
};
int main(){
    Remove list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(17);
    list.insert(20);
    cout<<"Before reverse the Linked List : ";
    list.display();
    //Reverse print the Linked List
    cout<<"After reverse the Linked List : ";
    list.reverse();
    list.display();
    //Remove Nth Node From End of List
    cout<<"After Remove Nth Node From End of List : ";
    list.removeAtSpecific(2);
    list.display();
    return 0;
}
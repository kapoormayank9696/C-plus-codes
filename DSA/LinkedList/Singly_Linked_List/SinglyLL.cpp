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

    //Insert at beginning
    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    //Insert at end
    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }
    
    //Insert at specific position
    void insertAtSpecific(int index,int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head == newNode;
        }
        else{
            Node* temp = head;
            int count = 1;
            while(temp != nullptr){
                if(count == index){
                    newNode->next = temp->next; 
                    temp->next = newNode; 
                    return;
                }
                temp = temp->next;
                count++;
            }
        }
    }

    //Delete from beginning
    void deleteAtBeginning(){
        if(head == nullptr){
            cout<<"Empty Linked List........";
        }else{
            head = head->next;
        }
    }

    //Delete from end
    void deleteAtEnd(){
        if(head == nullptr){
            cout<<"Empty Linked List..........";
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                if(temp->next->next == nullptr){
                    temp->next = nullptr;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    //Delete from the specific position
    void deleteAtSpecific(int index){
        if(head == nullptr){
            cout<<"Empty Linked List........";
        }else{
            Node* temp = head;
            int count = 0;
            while(temp->next != nullptr){
                if(count == index - 1){
                    temp->next = temp->next->next;
                }
                temp = temp->next;
                count++;
            }
        }
    }

    //Updating Linked List At Specific Position
    void updateAtSpecific(int index,int value){
        if(head == nullptr){
            cout<<"Empty Linked List........";
        }else{
            Node* temp = head;
            int count = 1;
            while(temp != nullptr){
                if(count == index){
                    temp->data = value;
                }
                temp = temp->next;
                count = count +1;
            }
        }
    }

    //Reverse the Linked List
    void reverse(){
        if(head == nullptr){
            cout<<"Empty Linked List............";
        }
        else{
            Node* prev = nullptr;
            Node* temp = head;
            Node* next = nullptr;
            while(temp != nullptr){
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }
            head = prev;
        }
    }

    //Display Linked List
    void display(){
        if(head == nullptr){
            cout<<"Empty Linked List"<<endl;
        }else{
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"->";
                temp = temp->next;
            }cout<<"null"<<endl;
        }
    }
};

// Main function to demonstrate the Singly Linked List operations
int main(){
    SinglyLL list;

    //Insert the elements in  Linked List
    cout<<"Insert elemets in the Linked List : ";
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);
    list.insert(-5);
    list.insert(0);

    //Display the Linked List 
    list.display();

    //Insert at beginnging
    cout<<"After inserting at beginning : ";
    list.insertAtBeginning(-1);
    list.display();

    //Insert at end
    cout<<"After inserting at end : ";
    list.insertAtEnd(25);
    list.display();

    //Insert at specific position
    cout<<"After inserting at specific position : ";
    list.insertAtSpecific(3,78);
    list.display();

    //Delete from beginning
    cout<<"After deleting from beginning : ";
    list.deleteAtBeginning();
    list.display();

    //Delete from end
    cout<<"After delete from end : ";
    list.deleteAtEnd();
    list.display();

    //Delete from specific position
    cout<<"After deleting from specific position : ";
    list.deleteAtSpecific(3);
    list.display();

    //Updating at specific position
    cout<<"After updating the Linked List : ";
    list.updateAtSpecific(3,29);
    list.display();

    //Reverse print the Linked List
    cout<<"Reverse print the Linked List : ";
    list.reverse();
    list.display();
    return 0;
}

// Searching In Circular Linked List Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Class for circular linked list
class CircularLL {
    // Public Access Modifier
    public:
    // Node class of circular linked list
    class Node {
        // Public Access Modifier
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

    // Method to insert the nodes into circular linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            newNode->next=head;
            return;
        }else {
            Node* temp=head;
            while(temp->next != head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    // Method of searching in circular linked list
    bool search(int value) {
        if(head == nullptr) {
            return false;
        }
        Node* temp=head;
        do{
            if(temp->data == value) {
                return true;
            }
            temp=temp->next;
        }while(temp != head);
        return false;
    }

    // Method to display the circular linked list
    void display() {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List....."<<endl;
            return;
        }
        Node* temp=head;
        do {
            cout<<temp->data<<" <--> ";
            temp=temp->next;
        }while(temp != head);
        cout<<"(head)"<<endl;
    }
    // Destructor for prevents to memory leaks,Correctly deletes circular structure,Handles all cases safely
    ~CircularLL() {
        if(head == nullptr) return;
        Node* temp = head->next;
        while(temp != head) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete head;
    }
};

int main() {
    CircularLL list;
    cout<<"Enter number of terms: ";
    int n,values;
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list.insert(values);
    }
    cout<<"Display the circular linked list: ";
    list.display();
    cout<<"Enter node for searching: ";
    cin>>values;
    if(list.search(values)) {
        cout<<"Yes, the node exists into circular linked list."<<endl;
    }else {
        cout<<"No, the node is not exist into circular linked list...."<<endl;
    }
    return 0;
}

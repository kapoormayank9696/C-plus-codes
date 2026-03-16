// Backward Traversing of Circular Linked List Algorithm Implmentation In C++
#include<iostream>
#include<stack>
using namespace std;
// Class of Circular Linked List
class CircularLL{
    // Public Access Modifier
    public:
    // Node class of Circular Linked List
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
    
    // Function to insert the node into circular linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            newNode->next=head;
            return;
        }
        Node* temp=head;
        // Find head node
        while(temp->next != head) {
            temp=temp->next;
        }
        temp->next=newNode; // last node points to second node
        newNode->next=head; // Move head towards
    }

    // Function to backward traversal the circular linked list
    void backwardTraversal() {
        if(head == nullptr) {
            cout<<"Empty Circular Linked List!!!!"<<endl;
            return;
        }
        // Initialized the stack
        stack<int> st;
        Node* temp=head;
        do{
            // Store the nodes into stack
            st.push(temp->data);
            temp=temp->next;
        }while(temp != head);
        // check stack is empty or not
        while(!st.empty()) {
            // Print the top stack node
            cout<<st.top()<<"<-->";
            // Remove the node from stack
            st.pop();
        }
        cout<<"(head)"<<endl;
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
    CircularLL* list=new CircularLL();
    int n,values;
    cout<<"Enter number of sizes: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list->insert(values);
    }
    cout<<"Display The Circular Linked List: ";
    list->display();
    cout<<"Backward Traversal Of Circular Linked List: ";
    list->backwardTraversal();
    return 0;
}


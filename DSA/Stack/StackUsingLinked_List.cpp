// Stack Implementation In C++ By Using Linked List
#include<iostream>
using namespace std;

// Node class
class Node{
    // Access Modifier and Data Members
    public:
    int data;
    Node* next;

    // Dynamic Constructor
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class StackUsingLinked_List{
    public:
    Node* top=nullptr;

    // Garbage Collection && Destructor
    ~StackUsingLinked_List() {
        while (!isEmpty()) pop();
    }

    // Check stack is an empty or not
    bool isEmpty(){
        return top == nullptr;
    }

    // Push Operation
    void push(int data){
        Node* newNode =new Node(data);
        newNode->next=top;
        top=newNode;
    }

    // Pop Operation
    int pop(){
        if(isEmpty()){
            cout<<"Stack is an empty!!!"<<endl;
            return -1;
        }
        Node* temp=top; // temporarily store node
        int k= temp->data; // store data
        top=top->next; // move top pointer
        delete temp; // free memory
        return k;
    }

    // Peek Operation
    int peek(){
        if(isEmpty()){
            cout<<"Stack is an empty!!!"<<endl;
            return -1;
        }
        return top->data;
    }

    // Display Operation
    void display(){
        if(isEmpty()){
            cout<<"Stack is an empty!!!"<<endl;
            return;
        }
        Node* temp=top;
        while(temp != nullptr){
            cout<< temp->data;
            if(temp->next != nullptr){
                cout<< "-->";
            }
            temp=temp->next;
        }
        cout<<"\n";
    }
};

// Main function
int main(){
    StackUsingLinked_List stack;
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        stack.push(value);
    }
    cout<<"Display the stack data: ";
    stack.display();
    cout<<"Top stack element: "<<stack.peek()<<endl;
    cout<<"Popped stack element: "<<stack.pop()<<endl;
    cout<<"After popped stack data: ";
    stack.display();
    cout<<"New top stack element: "<<stack.peek()<<endl;
    return 0;
}

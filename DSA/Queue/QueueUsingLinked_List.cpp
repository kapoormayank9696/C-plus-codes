// Queue Implementation In C++ By Using Linked List
#include<iostream>
using namespace std;

// Node class
class Node{
    // Access Modifier And Data Memebers
    public:
    int data;
    Node* next;

    // Dynamic constructor
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

// class of queue implementation algorithm
class QueueUsingLinked_List{
    public:
    Node* first=nullptr;
    Node* rear=nullptr;

    // Garbage Collection && Destructor
    ~QueueUsingLinked_List() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check queue is an empty or not
    bool isEmpty(){
        return first == nullptr;
    }

    // Enqueue Operation
    void enqueue(int data){
        Node* newNode =new Node(data);
        if(isEmpty()){
            first=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
    }

    // Dequeue Operation
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is an empty!!!"<<endl;
            return -1;
        }
        Node* temp=first; // temporarily store node
        int k=temp->data; // store data
        first=first->next; // move first pointer
        if(first == nullptr) rear = nullptr; // queue is now empty
        delete temp; // free memory
        return k;
    }

    // Peek Operation
    int peek(){
        if(isEmpty()){
            cout<<"Queue is an empty!!!"<<endl;
            return -1;
        }
        return first->data;
    }

    // Search Operation
    bool search(int value){
        bool check=false;
        Node* temp=first;
        while(temp != nullptr) {
            if(temp->data == value) {
                check=true;
                break;
            }
            temp=temp->next;
        }
        return check;
    }

    // Display Operation
    void display(){
        if(isEmpty()){
            cout<<"Queue is an empty!!!"<<endl;
            return;
        }
        Node* temp=first;
        while(temp != nullptr){
            cout<<temp->data;
            if(temp->next != nullptr){
                cout<<"-->";
            }
            temp=temp->next;
        }
        cout<<"\n";
    }
};

// Main function
int main(){
    QueueUsingLinked_List queue;
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        queue.enqueue(value);
    }
    cout<<"Display queue data: ";
    queue.display();
    cout<<"Top queue element: "<<queue.peek()<<endl;
    cout<<"Popped queue element: "<<queue.dequeue()<<endl;
    cout<<"After popped queue data: ";
    queue.display();
    cout<<"New top queue element: "<<queue.peek()<<endl;
    cout<<"Enter value for searching: ";
    int value;
    cin>>value;
    if(queue.search(value)) {
        cout<<"Yes,the value exist into queue.."<<endl;
    }else {
        cout<<"No,the value is not exist into queue.."<<endl;
    }
    return 0;
}


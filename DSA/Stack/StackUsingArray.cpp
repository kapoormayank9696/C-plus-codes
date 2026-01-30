// Stack Implementation In C++ By Using An Array
#include<iostream>
using namespace std;

// Stack implementation class 
class StackUsingArray{
    // Access Modifier And Data Memebers
    public:
    int* arr;
    int top,composition;

    StackUsingArray(int size){
        this->composition=size;
        this->arr=new int[composition];
        top=-1;
    }

    // Garbage Collection And Destructor
    ~StackUsingArray(){
        delete[] arr; // free memory
    }

    // Check stack is full or not
    bool isFull(){
        return top == composition-1;
    }

    // Check stack is an empty or not
    bool isEmpty(){
        return top == -1;
    }

    // Push Operation
    void push(int data){
        if(isFull()){
            cout<<"Stack is full no more data insert in it!!!"<<endl;
            return;
        }
        arr[++top]=data;
    }

    // Pop operation
    int pop(){
        if(isEmpty()){
            cout<<"Stack is an empty!!!"<<endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek Operation
    int peek(){
        if(isEmpty()){
            cout<<"Stack is an empty!!!"<<endl;
            return -1;
        }
        return arr[top];
    }

    // Display the stack data
    void display(){
        if(isEmpty()){
            cout<<"Stack is an empty!!!"<<endl;
            return;
        }
        for(int i=top; i>=0; i--){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};

// Main function
int main(){
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    StackUsingArray stack(n);
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

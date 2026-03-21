// Queue Implementation In C++ By Using An Array
#include<iostream>
using namespace std;

// Queue implementation class 
class QueueUsingArray{
    // Access Modifier And Data Memebers
    public:
    int* arr;
    int first,rear,composition;
    
    // Dynamic Constructor
    QueueUsingArray(int size){
        this->composition=size;
        this->arr=new int[composition];
        first=0;
        rear=-1;
    }

    // Garbage Collection && Destructor
    ~QueueUsingArray(){
        delete[] arr; // free memory
    }

    // Check queue is a full or not
    bool isFull(){
        return rear == composition-1;
    }

    // Check queue is an empty or not
    bool isEmpty(){
        return first > rear;
    }

    // Enqueue Operation
    void enqueue(int data){
        if(isFull()){
            cout<<"Queue is full no more data insert in it!!!"<<endl;
            return;
        }
        arr[++rear]=data;
    }

    // Dequeue Operation
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is an empty!!!"<<endl;
            return -1;
        }
        return arr[first++];
    }

    // Peek Operation
    int peek(){
        if(isEmpty()){
            cout<<"Queue is an empty!!!"<<endl;
            return -1;
        }
        return arr[first];
    }

    // Search Operation
    bool search(int value) {
        bool check=false;
        for(int i=first;i<=rear;i++) {
            if(arr[i] == value) {
                check=true;
                break;
            }
        }
        return check;
    }

    // Display the queue data
    void display(){
        if(isEmpty()){
            cout<<"Queue is an empty!!!"<<endl;
            return;
        }
        for(int i=first;i<=rear;i++){
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
    QueueUsingArray queue(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        queue.enqueue(value);
    }
    cout<<"Display the queue data: ";
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

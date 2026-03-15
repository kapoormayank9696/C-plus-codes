// Update The First Node From Circular Linked List Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Class of Circular Linked List
class Circularll{
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
    // Function to insert the nodes into circular linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            newNode->next=head;
            return;
        }
        else {
            Node* temp=head;
            while(temp->next != head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    // Function to update the node from beginning
    void updateAtSpecific(int index, int value) {
        if(head == nullptr || index <= 0) {
            cout << "Invalid index for updating the node...." << endl;
            return;
        }
        Node* temp = head;
        int count = 1;
        do {
            if(count == index) {
                temp->data = value;
                return;
            }
            temp = temp->next;
            count++;
        } while(temp != head);
        cout << "Index exceeds the length of the circular linked list...." << endl;
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

    // Destructor
    ~Circularll() {
        if(head != nullptr) {
            Node* temp = head->next;
            while(temp != head) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            delete head;
        }
    }
};

// Main function
int main() {
    Circularll* list=new Circularll();
    int n,values,index;
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list->insert(values);
    }
    cout<<"Display the Circular Linked List: ";
    list->display();
    cout<<"Enter index for updating: ";
    cin>>index;
    cout<<"Enter value for updating: ";
    cin>>values;
    list->updateAtSpecific(index,values);
    cout<<"After updating the Circular Linked List: ";
    list->display();
    return 0;
}


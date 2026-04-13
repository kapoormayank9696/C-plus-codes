// All Operation Are Apply In Circular Linked List Algorithms Implementation In C++
#include <iostream>
using namespace std;

// Node class of Circular Linked List
class Node {
    // Public Access Specifier
    public:   
    // Data Members
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
    public:
    Node* head = nullptr;  
    // Insert Node In Circular Linked List
    void insert(int data) {
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert Node at beginning of Circular Linked List
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert Node at position of Circular Linked List
    void insertAtPosition(int data, int position) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head->next=newNode;
            head=newNode;
        } else {
            if(position == 1) {
                insertAtBeginning(data);
                return;
            }
            Node* temp=head;
            int count=1;
            while(count<position-1 && temp->next!=head) {
                temp=temp->next;
                count++;
            }
            if(temp->next==head) {
                insertAtEnd(data);
                return;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    
    // Insert Node at end of Circular Linked List
    void insertAtEnd(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head->next=newNode;
            head=newNode;
        } else {
            Node* temp=head;
            while(temp->next!=head) {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    // Update Node at beginning of Circular Linked List
    void updateAtBeginning(int data) {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        head->data=data;
    }

    // Update Node at position of Circular Linked List
    void updateAtPosition(int data, int position) {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        Node* temp=head;
        int count=1;
        while(count<position && temp->next!=head) {
            temp=temp->next;
            count++;
        }
        if(temp->next==head) {
            cout<<"Position Not Found In Circular Linked List"<<endl;
            return;
        }
        temp->data=data;
    }

    // Update Node at end of Circular Linked List
    void updateAtEnd(int data) {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp->next!=head) {
            temp=temp->next;
        }
        temp->data=data;
    }

    // Delete Node at beginning of Circular Linked List
    void deleteAtBeginning() {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp->next!=head) {
            temp=temp->next;
        }
        Node* toDelete=head;
        head=head->next;
        temp->next=head;
        delete toDelete;
    }

    // Delete Node at position of Circular Linked List
    void deleteAtPosition(int position) {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        if(position == 1) {
            deleteAtBeginning();
            return;
        }
        Node* temp=head;
        int count=1;
        while(count<position-1 && temp->next!=head) {
            temp=temp->next;
            count++;
        }
        if(temp->next==head) {
            cout<<"Position Not Found In Circular Linked List"<<endl;
            return;
        }
        Node* toDelete=temp->next;
        temp->next=toDelete->next;
        delete toDelete;
    }

    // Delete Node at end of Circular Linked List
    void deleteAtEnd() {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        Node* temp=head;
        Node* prev=nullptr;
        while(temp->next!=head) {
            prev=temp;
            temp=temp->next;
        }
        if(prev==nullptr) {
            head=nullptr;
        } else {
            prev->next=head;
        }
        delete temp;
    }

    // Display Circular Linked List
    void display() {
        if(head == nullptr) {
            cout<<"Circular Linked List Is Empty"<<endl;
            return;
        }
        Node* temp=head;
        do {
            cout<<temp->data<<" ";
            temp=temp->next;
        } while(temp!=head);
        cout<<"(head)"<<endl;
    }
};

// Main Function
int main() {
    cout<<"Enter The Number Of Nodes In Circular Linked List: ";
    int n;
    cin>>n;
    CircularLinkedList circularLL;
    cout<<"Enter The Data For Nodes In Circular Linked List: ";
    for(int i=0; i<n; i++) {
        int data;
        cin>>data;
        circularLL.insert(data);
    }
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();

    // Insert Operations In Circular Linked List
    cout<<"Enter The Data To Insert At Beginning Of Circular Linked List: ";
    int data;
    cin>>data;
    circularLL.insertAtBeginning(data);
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<"Enter The Data To Insert Of Circular Linked List: ";
    cin>>data;
    cout<<"Enter The Position To Insert In Circular Linked List: ";
    int position;
    cin>>position;
    circularLL.insertAtPosition(data, position);
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<"Enter The Data To Insert At End Of Circular Linked List: ";
    cin>>data;
    circularLL.insertAtEnd(data);
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<endl;

    // Update Operations In Circular Linked List
    cout<<"Enter The Data To Update At Beginning Of Circular Linked List: ";
    cin>>data;
    circularLL.updateAtBeginning(data);
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<"Enter The Position To Update In Circular Linked List: ";
    cin>>position;
    cout<<"Enter The Data To Update In Circular Linked List: ";
    cin>>data;
    circularLL.updateAtPosition(data, position);
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<"Enter The Data To Update At End Of Circular Linked List: ";
    cin>>data;
    circularLL.updateAtEnd(data);
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<endl;

    // Delete Operations In Circular Linked List
    circularLL.deleteAtBeginning();
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<"Enter The Position To Delete In Circular Linked List: ";
    cin>>position;
    circularLL.deleteAtPosition(position);
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    circularLL.deleteAtEnd();
    cout<<"Displaying Circular Linked List: ";
    circularLL.display();
    cout<<endl;
    return 0;
}


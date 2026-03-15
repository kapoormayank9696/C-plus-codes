// Merge Two Sorted Liniked List Algorithms Implementation In C++
#include<iostream>
using namespace std;
// Class of Linked List
class Singlyll {
    // Public Access Modifier
    public:
    // Node class of Singly linked list
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
    // Function to insert the nodes into linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next != nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
    }

    // Function to display the linked list
    void display() {
        if(head == nullptr) {
            cout<<"Empty Linked List!!!!"<<endl;
            return;
        }
        Node* temp=head;
        while(temp != nullptr) {
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }

    // Function to sort the linked list
    static Node* sorted(Node* head) {
        if(head == nullptr || head->next == nullptr)
        return head;
        Node* i;
        Node* j;
        for(i = head; i->next != nullptr; i = i->next) {
            for(j = i->next; j != nullptr; j = j->next) {
                if(i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
        return head;
    }

    // Function to merge two sorted linked lists
    static Node* mergeLists(Node* list1,Node* list2) {
        Node* dummy=new Node(0);
        Node* temp=dummy;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->data <= list2->data) {
                temp->next=list1;
                list1=list1->next;
            }else {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1 != nullptr) {
            temp->next=list1;
        }else {
            temp->next=list2;
        }
        return dummy->next;
    }
};

// Main function
int main() {
    Singlyll* list1=new Singlyll();
    Singlyll* list2=new Singlyll();
    int n,values,m;
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list1->insert(values);
    }
    cout<<"\nDisplay first linked list: ";
    list1->display();
    Singlyll::Node* head1=list1->sorted(list1->head);
    cout<<"Display the sorted list: ";
    list1->display();
    cout<<"Enter number of terms: ";
    cin>>m;
    cout<<"Enter nodes: ";
    for(int i=0;i<m;i++) {
        cin>>values;
        list2->insert(values);
    }
    cout<<"\nDisplay second linked list: ";
    list2->display();
    Singlyll::Node* head2=list2->sorted(list2->head);
    cout<<"Display the sorted list: ";
    list2->display();
    cout<<"\nMerged Linked List: ";
    // Store the merge list head into merged variable
    Singlyll::Node* merged = list1->mergeLists(list1->head, list2->head);
    // Define the merged head into temp variable
    Singlyll::Node* temp = merged;
    // Print the linked list after mergeing two sorted lists
    while(temp != nullptr) {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"nullptr"<<endl;
    return 0;
}


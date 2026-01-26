// Leet Code Problem 1721: Swapping Nodes in a Linked List
#include<iostream>
using namespace std;

class ListNode{
    // Default Access Modifier And Data Memebers
    public:
    int data;
    ListNode* next;
    // Parameterized Constructor
    public:
    ListNode(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class Solution1721{
    public:
    ListNode* head=nullptr;
    // Method to insert the elements in linked list
    void insert(int data){
        ListNode* newNode = new ListNode(data);
        if(head == nullptr){
            head = newNode;
        }else{
            ListNode* temp=head;
            while(temp->next != nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    // Method to swapping the node elements from linked list
    void swapNodes(int k) {
        ListNode* temp=head;
        int count=1;
        int n=0;
        while(temp != nullptr){
            temp=temp->next;
            n++;
        }
        ListNode* first=head;
        for(int i=1;i<k;i++){
            first=first->next;
        }
        ListNode* second=head;
        for(int i=1;i<n-k+1;i++){
            second=second->next;
        }
        int c=first->data;
        first->data=second->data;
        second->data=c;
    }

    // Method to display the linked list data
    void display(){
        if(head == nullptr){
            cout<<"Empty Linked List!!!"<<endl;
        }else{
            ListNode* temp=head;
            while(temp != nullptr){
                cout<<temp->data<<"-->";
                temp=temp->next;
            }
            cout<<"nullptr"<<endl;
        }
    }
};

// Main function 
int main(){
    Solution1721 list;
    cout<<"Enter number of terms: ";
    int n,value;
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>value;
        list.insert(value);
    }
    cout<<"Original Linked List: ";
    list.display();
    cout<<"Enter position of node: ";
    int k;
    cin>>k;
    list.swapNodes(k);
    cout<<"After swapping nodes element of linked list: ";
    list.display();
    return 0;
}

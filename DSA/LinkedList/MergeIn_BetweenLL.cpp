// Merge In Between Linked Lists Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Node class of Singly Linked List
class ListNode {

    // Public Access Modifier
    public:
    int val;
    ListNode *next;

    // Parameterized Constructor
    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }
};

// Solution class to implement the merge in between operation
class Solution {
    // Public Access Modifier
    public:
    ListNode* head = nullptr;

    // Insert Operation
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Merge In Between Operation
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        // Finding the node at position a-1 in list1
        ListNode* curr = list1;
        
        // Traversing to the node just before position a
        for(int i=0; i< a-1; i++) {
            curr = curr->next;
        }

        ListNode* prevA = curr;
        
        // Traversing to the node at a point position to b point position
        ListNode* temp = prevA;
        for(int i=a; i<b; i++) {
            temp = temp->next;
        }

        ListNode* afterB = temp->next;
        
        // Traversing to the end of list2
        ListNode* l2 = list2;
        while (l2->next != nullptr) {
            l2 = l2->next;
        }

        // Connecting the nodes to merge list2 in between list1
        prevA->next = list2;
        l2->next = afterB;
        return list1;
    }

    // Display Operation
    void display() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << "-->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// Main function
int main() {
    Solution s;

    // Creating first linked list
    s.insert(10);
    s.insert(1);
    s.insert(13);
    s.insert(6);
    s.insert(9);
    s.insert(5);

    cout << "First Linked List: ";
    s.display();

    // Creating second linked list
    ListNode* list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    cout << "Second Linked List: ";
    ListNode* temp = list2;
    while (temp != nullptr) {
        cout << temp->val << "-->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;

    // Merging second linked list into first linked list between positions 3 and 4
    ListNode* mergedList = s.mergeInBetween(s.head, 3, 4, list2);

    cout << "Merged Linked List: ";
    s.display();

    return 0;
}


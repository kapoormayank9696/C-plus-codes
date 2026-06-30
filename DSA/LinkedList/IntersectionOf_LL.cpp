// Palindrome Singly Linked List Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// class of Singly Linked List
class ListNode {
    // Public Access Modifier
    public:
    int val;
    ListNode *next;
    // Parmaterized Constructor
    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }
};

class Solution {
    // Public Access Modifier
    public:
    // Intersection Operation
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while(p1 != p2) {
            p1 = (p1 == nullptr)? headB: p1->next;
            p2 = (p2 == nullptr)? headA: p2->next;
        }
        return p1;
    }
    
    // Function to insert the node into singly linked list
    void insertNode(ListNode** head, int value) {
        ListNode* newNode = new ListNode(value);
        if (*head == nullptr) {
            *head = newNode;
        } else {
            ListNode* temp = *head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Print the Singly Linked List
    void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Solution solution;

    // Common part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A: ";
    solution.printList(headA);

    cout << "List B: ";
    solution.printList(headB);

    ListNode* ans = solution.getIntersectionNode(headA, headB);

    if (ans != nullptr)
        cout << "Intersection Node = " << ans->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}

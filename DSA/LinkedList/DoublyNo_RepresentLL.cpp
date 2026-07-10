// Double a Number Represented as a Linked List Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Node class of Doubly Linked List
class ListNode {

    // Public Access Modifier
    public:
    int val;
    ListNode *next;
    ListNode *prev;
    // Parameterized Constructor
    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Solution class to implement the double number operation
class Solution {
    // Public Access Modifier
    public:
    // Insert Operation
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
            newNode->prev = temp;
        }
    }

    // Double Number Operation
    ListNode* doubleNumber(ListNode* head) {
        if (head == nullptr) return nullptr;

        if(head->val >= 5) {
            ListNode* newNode = new ListNode(0);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        ListNode* temp = head;
        while(temp != nullptr) {
            temp->val = (temp->val * 2) % 10;
            if(temp->next && temp->next->val >= 5) {
                temp->val ++;
            }
            temp = temp->next;
        }
        return head;
    }
    
    // Display Operation
    void displayList(ListNode* head) {
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
    ListNode* head = nullptr;

    // Insert nodes into the doubly linked list
    solution.insertNode(&head, 1);
    solution.insertNode(&head, 2);
    solution.insertNode(&head, 3);
    solution.insertNode(&head, 4);
    solution.insertNode(&head, 5);

    cout << "Original List: ";
    solution.displayList(head);

    // Double the number represented by the linked list
    head = solution.doubleNumber(head);

    cout << "Doubled List: ";
    solution.displayList(head);

    return 0;
}

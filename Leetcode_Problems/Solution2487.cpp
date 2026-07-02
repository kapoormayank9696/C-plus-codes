// LeetCode Problem 2487: Remove Node From Linked List
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

// Solution class to implement the remove node operation
class Solution {
    // Public Access Modifier
    public:
    ListNode** head = new ListNode*(nullptr);

    // Insert Operation
    void insertNode(int value) {
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

    // Reverse Operation
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Remove Node Operation
    ListNode* removeNode(ListNode* head) {
        if (head == nullptr) return nullptr;

        head = reverse(head);
        int max = head->val;
        ListNode* temp = head;

        while(temp->next != nullptr) {
            if (temp->next->val < max) {
                temp->next = temp->next->next;
            }else {
                temp = temp->next;
                max = temp->val;
            }
        }
        return reverse(head);
    }

    // Display Operation
    void display(ListNode* head) {
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
    Solution solution;
    solution.insertNode(5);
    solution.insertNode(2);
    solution.insertNode(13);
    solution.insertNode(3);
    solution.insertNode(8);
    
    cout << "Original List: ";
    solution.display(*solution.head);

    ListNode* newHead = solution.removeNode(*solution.head);
    cout << "List after removing nodes: ";
    solution.display(newHead);
    return 0;
}
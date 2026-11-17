// LeetCode Problem 1290 : Convert Binary Number in a Linked List to Integer
#include <iostream>
using namespace std;

// Class Of Listnode
class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode* prev;

    // Parameterized Constructor
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Solution Class
class Solution { 
    public:
    // Get Decimal Value function
    int getDecimalValue(ListNode* head) {
        if (head == nullptr) {
            return 0;
        }

        int sum = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            sum = sum * 2 + temp->val;
            temp = temp->next;
        }

        return sum;
    }
};

// Main function
int main() {
    // Creating Linked List: 1 -> 0 -> 1
    ListNode* head = new ListNode(1);

    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    // Display Linked List
    cout << "Binary Number: ";

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    // Get Decimal Value
    Solution sol;

    cout << "\nDecimal Value: " << sol.getDecimalValue(head);

    // Free allocated memory
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
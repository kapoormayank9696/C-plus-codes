// Double a Number Represented as a Linked List Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Node class of Doubly Linked List
class ListNode {
    public:
    int val;
    ListNode* next;

    // Parameterized Constructor
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Solution class to double the number represented as a linked list
class Solution {
    public:
    ListNode* head = nullptr;
    // Insert Operation
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to double the number represented as a linked list
    ListNode* doubleNumber(ListNode* head) {
        if (head != nullptr && head->val >= 5) {
            ListNode* newNode = new ListNode(0);
            newNode->next = head;
            head = newNode;
        }
        ListNode* current = head;
        while (current != nullptr) {
            current->val = current->val * 2%10;
            if(current->next != nullptr && current->val >= 5){
                current->val ++;
            }
            current = current->next;
        }
        return head;
    }

    // Display Operation
    void display(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val;
            current = current->next;
        }
        cout << endl;
    }    
};

// Main function
int main() {
    Solution solution;
    
    // Create a linked list representing the number 1234
    solution.insert(1);
    solution.insert(2);
    solution.insert(3);
    solution.insert(4);
    
    cout << "Original Number: ";
    solution.display(solution.head);
    
    // Double the number represented as a linked list
    ListNode* doubledHead = solution.doubleNumber(solution.head);
    cout << "Doubled Number: ";
    solution.display(doubledHead);
    return 0;
}

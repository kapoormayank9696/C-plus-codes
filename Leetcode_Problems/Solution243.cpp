// LeetCode Problem 243: Palindrome Linked List

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }

        // Copy the original linked list
        ListNode* copiedList = copyList(head);

        // Reverse the copied linked list
        ListNode* reversedList = reverseList(copiedList);

        // Compare 
        ListNode* temp1 = head;
        ListNode* temp2 = reversedList;
        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1->val != temp2->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }

    // Copy the Linked List
    ListNode* copyList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* newHead = new ListNode(head->val);
        ListNode* current = newHead;
        ListNode* originalCurrent = head->next;

        while (originalCurrent != nullptr) {
            current->next = new ListNode(originalCurrent->val);
            current = current->next;
            originalCurrent = originalCurrent->next;
        }
        return newHead;
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
    ListNode* head = nullptr;
    Solution solution;
    vector<int> values = {1, 2, 3, 2, 1}; // Example values for the linked list
    for (int value : values) {
        solution.insertNode(&head, value);
    }
    cout << "Original Linked List: ";
    solution.printList(head);
    cout << "Is Palindrome: " << (solution.isPalindrome(head) ? "Yes" : "No") << endl;
    return 0;
}


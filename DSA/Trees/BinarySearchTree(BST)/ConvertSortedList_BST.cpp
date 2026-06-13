//  Convert Sorted List to Binary Search Tree Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list and binary tree node.
class ListNode {
    public:
    int val;
    ListNode* next;

    // Parameterized Constructor
    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }
};

// Definition for a binary search tree node.
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to find the middle element of the linked list
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    // Fast and slow pointer Method to find the middle node of the linked list
    while(fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != nullptr) {
        prev->next = nullptr; // Split the linked list into two halves
    }
    return slow; // Return the middle node
}

// Function to convert sorted linked list to binary search tree
TreeNode* sortedListToBST(ListNode* head) {
    if(head == nullptr) {
        return nullptr;
    }
    if(head->next == nullptr) {
        return new TreeNode(head->val);
    }
    ListNode* mid = findMiddle(head);
    
    // Create a new tree node
    TreeNode* root = new TreeNode(mid->val); 

    // Recursively build the left subtree
    root->left = sortedListToBST(head);
    // Recursively build the right
    root->right = sortedListToBST(mid->next);

    return root;
}

// Function to print the binary search tree(for testing purposes)
void Traversal(TreeNode* root) {
    if(root == nullptr) return;

    Traversal(root->left);
    cout << root->val << " ";
    Traversal(root->right);
}

// Main function
int main() {
    vector<int> sortedList = {-10, -3, 0, 5, 9}; // Example sorted linked list
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    // Create the linked list from the sorted array
    for(int num : sortedList) {
        if(head == nullptr) {
            head = new ListNode(num);
            current = head;
        } else {
            current->next = new ListNode(num);
            current = current->next;
        }
    }
    TreeNode* bstRoot = sortedListToBST(head); // Convert the sorted linked list to a binary search tree
    cout << "Traversal of the BST: ";
    Traversal(bstRoot); // Print the in-order traversal of the BST
    return 0;
}



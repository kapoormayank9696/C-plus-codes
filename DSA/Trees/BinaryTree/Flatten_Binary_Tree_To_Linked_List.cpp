// Flatten Binary Tree to Linked List Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Node class of Binary Tree
class TreeNode {
    
    // Public Access Modifier
    public:

    // Data Members
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

// Solution class to flatten the binary tree to linked list
class Solution {
    public:

    // Build the binary tree
    TreeNode* buildTree(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = buildTree(root->left, val);
        } else {
            root->right = buildTree(root->right, val);
        }
        return root;
    }

    TreeNode* prev = nullptr; 

    // Function to flatten the binary tree to linked list
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    // Print the Binary Tree in Preorder Traversal
    void printPreorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
};

// Main function
int main() {
    int nums[] = {1, 2, 5, 3, 4, 6};
    Solution sol;
    TreeNode* root = nullptr;
    for (int num : nums) {
        root = sol.buildTree(root, num);
    }

    cout << "Original Binary Tree (Preorder Traversal): ";
    sol.printPreorder(root);

    cout << "\nFlattened Binary Tree to Linked List (Preorder Traversal): ";
    sol.flatten(root);
    sol.printPreorder(root);
    return 0;
};

// Flatten Binary Tree to Linked List Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Node class of Binary Tree
class TreeNode {

    // Public Access Specifier
    public:
    // Data Members
    int val;
    TreeNode *left;
    TreeNode *right;

    // Parameterized Constructor
    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Solution class
class Solution {
    public:
    int index = -1;

    // Build the Binary Tree
    TreeNode *buildTree(int nums[], int n) {

        index++;

        // Check index first
        if (index >= n || nums[index] == -1) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(nums[index]);

        root->left = buildTree(nums, n);
        root->right = buildTree(nums, n);

        return root;
    }

    TreeNode *prev = nullptr;

    // Flatten Binary Tree to Linked List
    void flatten(TreeNode *root) {

        if (root == nullptr) {
            return;
        }

        // Reverse Preorder: Right -> Left -> Root
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;

        prev = root;
    }

    // Print Preorder
    void printPreorder(TreeNode *root) {

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

    int nums[] = {
        1, 2, 3, -1, -1, 4, -1, -1,
        5, -1, 6, -1, -1};

    Solution sol;

    int n = sizeof(nums) / sizeof(nums[0]);

    TreeNode *root = sol.buildTree(nums, n);

    cout << "Original Binary Tree (Preorder Traversal): ";
    sol.printPreorder(root);

    cout << "\nFlattened Binary Tree to Linked List: ";

    sol.flatten(root);

    sol.printPreorder(root);

    return 0;
}
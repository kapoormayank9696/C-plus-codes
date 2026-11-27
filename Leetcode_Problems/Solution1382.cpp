// LeetCode Problem 1382 : Balance a Binary Search Tree
#include <iostream>
#include <vector>
using namespace std;

// Node class for the binary tree
class TreeNode {

    // Data members
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

// Solution class
class Solution {
    public:

    // Function to insert the nodes in the binary tree
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Left Subtree
        if (val < root->val) {
            root->left = insert(root->left, val);
        }

        // Right Subtree
        else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    // Function to print the binary tree preorder
    void printPreOrder(TreeNode* root) {
        if (root != nullptr) {
            cout << root->val << " ";
            printPreOrder(root->left);
            printPreOrder(root->right);
        }
    }

    // Inorder Function
    void inorder(TreeNode* root, vector<int> &list) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }

    // Build Tree
    TreeNode* buildTree(vector<int> &list, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(list[mid]);
        node->left = buildTree(list, start, mid - 1);
        node->right = buildTree(list, mid + 1, end);
        return node;
    }

    // Balance BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> list;
        inorder(root, list);
        return buildTree(list, 0, list.size() - 1);
    }
};

// Main Function
int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // Insert Nodes
    root = sol.insert(root, 1);
    root = sol.insert(root, 2);
    root = sol.insert(root, 3);
    root = sol.insert(root, 4);

    cout << "Original BST Preorder: ";
    sol.printPreOrder(root);
    cout << endl;

    // Balance BST
    TreeNode* balancedRoot = sol.balanceBST(root);

    cout << "Balanced BST Preorder: ";
    sol.printPreOrder(balancedRoot);
    cout << endl;

    return 0;
}

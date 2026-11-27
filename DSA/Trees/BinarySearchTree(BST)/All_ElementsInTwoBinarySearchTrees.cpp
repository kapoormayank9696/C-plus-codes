// All Elements in Two Binary Search Trees Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <algorithm>
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
    static TreeNode* insert(TreeNode* root, int val) {
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
    static void printPreOrder(TreeNode* root) {
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

    // All Elements in Two Binary Search Trees Function
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;

        inorder(root1, result);
        inorder(root2, result);

        sort(result.begin(), result.end());

        return result;
    }
};

// Main Function
int main() {
    Solution sol;

    TreeNode* root1 = nullptr;
    TreeNode* root2 = nullptr;

    // First BST
    root1 = sol.insert(root1, 2);
    root1 = sol.insert(root1, 1);
    root1 = sol.insert(root1, 4);

    // Second BST
    root2 = sol.insert(root2, 1);
    root2 = sol.insert(root2, 0);
    root2 = sol.insert(root2, 3);

    cout << "First BST Preorder: ";
    sol.printPreOrder(root1);
    cout << endl;

    cout << "Second BST Preorder: ";
    sol.printPreOrder(root2);
    cout << endl;

    // Get All Elements
    vector<int> result = sol.getAllElements(root1, root2);

    cout << "All Elements in Sorted Order: ";
    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;
    return 0;
}

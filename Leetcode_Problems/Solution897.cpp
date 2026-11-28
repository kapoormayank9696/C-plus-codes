// LeetCode Problem 897 : Increasing Order Search Tree
#include <iostream>
using namespace std;

class IncreasingOrderSearchTree {
    public:
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

        // Function to print the binary tree pre order
        void printPreOrder(TreeNode* root) {
            if (root != nullptr) {
                cout << root->val << " ";
                printPreOrder(root->left);
                printPreOrder(root->right);
            }
        }

        // Helper Function Of Increasing BST
        TreeNode* increasingBST(TreeNode* root, TreeNode* tail) {
            if (root == nullptr)
                return tail;

            TreeNode* node = increasingBST(root->left, root);
            root->left = nullptr;
            root->right = increasingBST(root->right, tail);

            return node;
        }

        // Function Of Increasing BST
        TreeNode* increasingBST(TreeNode* root) {
            return increasingBST(root, nullptr);
        }
    };
};

// Main function
int main() {

    IncreasingOrderSearchTree::Solution sol;

    IncreasingOrderSearchTree::TreeNode* root = nullptr;

    // Insert nodes into BST
    root = sol.insert(root, 5);
    root = sol.insert(root, 3);
    root = sol.insert(root, 6);
    root = sol.insert(root, 2);
    root = sol.insert(root, 4);
    root = sol.insert(root, 8);
    root = sol.insert(root, 1);
    root = sol.insert(root, 7);
    root = sol.insert(root, 9);

    // Original BST
    cout << "Original BST Preorder: ";
    sol.printPreOrder(root);

    // Increasing Order BST
    IncreasingOrderSearchTree::TreeNode* result = sol.increasingBST(root);
    cout << "\n\nIncreasing Order BST Preorder: ";
    sol.printPreOrder(result);

    return 0;
}

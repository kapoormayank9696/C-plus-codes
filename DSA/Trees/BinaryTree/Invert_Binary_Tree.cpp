// Invert Binary Tree Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Class TreeNode 
class TreeNode {

    // Public Specifier
    public:

    // Data Members
    int val;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Solution Class
class Solution {
    
    // Public Specifier
    public:
    int index = -1;

    // Insert into the binary tree
    TreeNode* insertTreeNode(int nums[], int n) {
        index++;
        if (index >= n || nums[index] == -1) {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(nums[index]);

        // Recursive Calls
        newNode->left = insertTreeNode(nums, n);
        newNode->right = insertTreeNode(nums, n);
        return newNode;
    }

    // Function to invert a binary tree
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        // Recursive Calls
        invertTree(root->left);
        invertTree(root->right);

        // Swap root's children
        TreeNode* current = root->left;
        root->left = root->right;
        root->right = current;

        return root;
    }

    // Function to print the binary tree in pre-order
    void printPreOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // Recursive Calls
        cout << root->val << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
};

// Main function
int main() {
    int nums[] = {4, 2, 1, -1, -1, 3, -1, -1, 7, 6, -1, -1, 9, -1, -1};
    int n = sizeof(nums) / sizeof(nums[0]);
    Solution solution;

    TreeNode* root = solution.insertTreeNode(nums, n);
    cout << "Original Binary Tree (Pre-Order): ";
    solution.printPreOrder(root);
    cout << endl;

    root = solution.invertTree(root);
    cout << "Inverted Binary Tree (Pre-Order): ";
    solution.printPreOrder(root);
    return 0;
}

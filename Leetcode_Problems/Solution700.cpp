// LeetCode Problem 700 : Search In Binary Search Tree
#include<iostream>
using namespace std;

// Class TreeNode Of BST
class TreeNode {
    
    // Public Specifier
    public:

    // Data Members
    int val;
    TreeNode* left;
    TreeNode* right;

    // Partameterized Constructor
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Solution class
class Solution {

    // Public Specifier
    public:

    // Insert nodes into BST
    TreeNode* insert(TreeNode* root,int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }

        // Recursive Function
        if(val < root->val) {
            root->left=  insert(root->left,val);
        }

        if(root->val < val) {
            root->right = insert(root->right,val);
        }

        return root;
    }

    // Search in Binary Search Tree
    TreeNode* searchBST(TreeNode* root,int target) {
        if(root == nullptr) {
            return nullptr;
        }

        if(root->val == target) {
            return root;
        }

        // Recursive Function
        if(target < root->val) {
            return searchBST(root->left,target);
        }

        return searchBST(root->right, target);
    }

    // Function to print the BST (Preorder)
    void printBST(TreeNode *root) {

        if (root == nullptr) {
            return;
        }

        cout << root->val << " " ;

        // Recursive Function
        printBST(root->left);
        printBST(root->right);
    }
};

// Main function
int main() {
    int values[] = {4, 2, 7, 1, 3};
    Solution solution;
    TreeNode *root = nullptr;

    for (int value : values) {
        root = solution.insert(root, value);
    }
    cout << "Preorder Traversal of the BST: ";
    solution.printBST(root);
    cout << endl;
    
    int target = 2;

    TreeNode *result = solution.searchBST(root, target);

    if (result != nullptr) {
        cout << "Search in Binary Search Tree: " << result->val << endl;
    } else {
        cout << "Value not found in BST." << endl;
    }

    return 0;
}

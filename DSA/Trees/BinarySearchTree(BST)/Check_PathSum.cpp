// Check Path Sum in a Binary Search Tree (BST) Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Class Node Of Singly Linked List
class ListNode {
    public:
    int value;
    ListNode* next;
    // Parameterized Constructor
    ListNode(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

// Class Node of Binary Search Tree
class TreeNode {
    public:
    int value;
    TreeNode* left;
    TreeNode* right;
    // Parameterized Constructor
    TreeNode(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Class Binary Search Tree
class BinarySearchTree {
    public:
    // Function to Build the Binary Search Tree
    TreeNode* buildBST(TreeNode* root, int data) {
        if(root == nullptr) {
            root = new TreeNode(data);
            return root;
        }
        if(data < root->value) {
            root->left = buildBST(root->left, data);
        } else {
            root->right = buildBST(root->right, data);
        }
        return root;
    }

    // Function to check if a path exists with the given sum
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        targetSum -= root->value;
        
        if (!root->left && !root->right)  return targetSum == 0;

        return hasPathSum(root->left, targetSum) ||
        hasPathSum(root->right, targetSum);
    }

    // Function to print the Binary Search Tree in Inorder Traversal
    void inorderTraversal(TreeNode* root) {
        if(root != nullptr) {
            inorderTraversal(root->left);
            cout << root->value << " ";
            inorderTraversal(root->right);
        }
    }
};

// Main function
int main() {
    BinarySearchTree bst;
    
    TreeNode* root = nullptr;

    vector<int> nodes = {5, 4, 11, 7, 2, 8, 13, 4, 1};

    for(int val : nodes) {
        root = bst.buildBST(root, val);
    }

    cout << "Binary Tree (Inorder): ";
    bst.inorderTraversal(root);

    int targetSum = 22;
    cout << "\nPath with sum exists: "
         << boolalpha
         << bst.hasPathSum(root, targetSum)
         << endl;

    return 0;
}
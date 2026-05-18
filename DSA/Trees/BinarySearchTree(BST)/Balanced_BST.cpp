// Balanced Binary Search Tree (BST) implementation in C++
#include <iostream>
#include <algorithm>
using namespace std;

// Node class of Binary Search Tree
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class to insert the nodes in BST
class BinarySearchTree {
    public:
    
    // Recursive function to insert a node in the BST
    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }
        // Left Subtree
        if (value < root->data) {
            root->left = insertRec(root->left, value);
        }
        // Right Subtree
        else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }
        return root;
    }
};

// Function to print the BST (Preorder)
void printBST(TreeNode* root) {

    if(root == nullptr) {
        return;
    }

    cout << root->data << " ";

    printBST(root->left);
    printBST(root->right);
}

// Function to check whether BST is balanced
int checkBalance(TreeNode* root) {

    if(root == nullptr) {
        return 0;
    }

    int leftHeight = checkBalance(root->left);
    int rightHeight = checkBalance(root->right);

    // Tree already unbalanced
    if(leftHeight == -1 || rightHeight == -1) {
        return -1;
    }

    // Current node unbalanced
    if(abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

// Function to check balance
bool balanceBST(TreeNode* root) {
    return checkBalance(root) != -1;
}

// Main function
int main() {
    int values[] = {9,3,20,15,7};
    BinarySearchTree bst;
    TreeNode* root = nullptr;
    for(int value : values) {
        root = bst.insertRec(root, value);
    }
    cout << "Preorder Traversal of the BST: ";
    printBST(root);
    cout << endl;
    cout << "Is the BST balanced? "
         << (balanceBST(root) ? "Yes" : "No") << endl;

    return 0;
}
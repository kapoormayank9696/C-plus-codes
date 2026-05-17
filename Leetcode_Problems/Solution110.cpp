// LeetCode Problem 110: Balanced Binary Tree

#include <iostream>
#include <cmath>
using namespace std;

// Node class of Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to insert nodes in BST
Node* insert(Node* root, int val) {

    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Preorder traversal
void print(Node* root) {

    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    print(root->left);
    print(root->right);
}

// Function to calculate height
int checkHeight(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = checkHeight(root->left);

    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight(root->right);

    if (rightHeight == -1) {
        return -1;
    }

    // Check balance condition
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    // Return height
    return 1 + max(leftHeight, rightHeight);
}

// Function to check if tree is balanced
bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

// Main function
int main() {

    // int nums[] = {9, 3, 20, 15, 7};
    int nums[] = {1,2,2,3,3,-1,-1,4,4};

    Node* root = nullptr;

    for (int num : nums) {
        root = insert(root, num);
    }

    cout << "Preorder Traversal: ";
    print(root);

    cout << "\nIs Balanced? "
         << (isBalanced(root) ? "Yes" : "No");

    return 0;
}
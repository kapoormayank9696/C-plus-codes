// Is Symmetry In A Binary Search Tree Algorithm Implementation In C++
#include <iostream>
#include<algorithm>
using namespace std;

// class of Binary Search Tree
class TreeNode {
    public :

    // Data Member of the class
    int data;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor of the class
    TreeNode(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};


// Function to insert the node in binary tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    // Left subtree
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } 
    // Right subtree
    else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Print the binary Search tree
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// Function to check binary search tree is mirror of itself
bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left == nullptr || right == nullptr) {
        return false;
    }
    if (left->data != right->data) return false;
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Function to check if the binary search tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    return isMirror(root->left, root->right);
}

// Main function
int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
    cout << "Binary Search Tree: ";
    printTree(root);
    cout << endl;
    cout << "Is the binary search tree symmetric? " << boolalpha << isSymmetric(root) << endl;
    return 0;
}

// LeetCode Problem 101: Symmetric Tree
#include <iostream>
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

// class to insert the node in binary tree
class BinaryTree {
    public:
    int index = -1;
    // Function to insert the node in binary tree
    TreeNode* insertNode(int arr[], int n) {
        index++;
        if (index >= n || arr[index] == -1) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(arr[index]);
        // Recursive Calls for left and right subtrees
        newNode->left = insertNode(arr, n);
        newNode->right = insertNode(arr, n);
        return newNode;
    }

    // Function to check binary tree is mirror of itself
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

    // Function to check if the binary tree is symmetric
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};

// Function to print the binary tree
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// Main function 
int main() {
    int arr[] = {1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
    BinaryTree bt;
    TreeNode* root = bt.insertNode(arr, n);
    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;
    cout << "The binary tree is symmetric." <<boolalpha << bt.isSymmetric(root) << endl;
}


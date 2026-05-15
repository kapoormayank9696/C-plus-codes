// Validate Binary Search Tree Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Node class for a binary tree
class TreeNode {
    // Public Access Specifier
    public:
    // Data Members
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

// Function to insert a node in the binary tree
void insertNode(TreeNode* &root, int data) {
    if (root == nullptr) {
        root = new TreeNode(data);
        return;
    }
    if (data < root->val) {
        insertNode(root->left, data);
    } else {
        insertNode(root->right, data);
    }
}

// Function to print the Binary Search Tree(BST)
void printBST(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printBST(root->left);
    printBST(root->right);
}

// Function to validate if a binary tree is a binary search tree
bool checkBST(TreeNode* root, TreeNode* min = nullptr, TreeNode* max = nullptr) {
    if (root == nullptr) {
        return true;
    }
    if ((min != nullptr && root->val <= min->val) || (max != nullptr && root->val >= max->val)) {
        return false;
    }
    return checkBST(root->left, min, root) && checkBST(root->right, root, max);
}

// Function to check if a binary tree is a valid binary search tree
bool isValidBST(TreeNode* root) {
    return checkBST(root,nullptr, nullptr);
}

// Main function
int main() {
    int nodes[]={5, 3, 7, 2, 4, 6, 8};
    TreeNode* root = nullptr;
    for (int data : nodes) {
        insertNode(root, data);
    }
    cout<< "\nPrint Binary Tree";
    printBST(root);
    
    cout << "\nIs Valid BST: "
         << boolalpha
         << isValidBST(root)
         << endl;
    return 0;
}

// Range Sum of BST Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Tree Class
class TreeNode {
    // Public Access Specifier
    public:

    // Data Members
    int val;
    TreeNode *left;
    TreeNode *right;

    // Parameterized Constructor
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to insert values in the binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    // Recursion to insert the value in the left or right subtree based on the value
    if (value < root->val) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function of Range sum Of BST
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr)
        return 0;

    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    else if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }
    else {
        return root->val + rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
}

// Function to print BST
void printBST(TreeNode* root) {
    if(root == nullptr) return;

    cout << root->val << " ";
    printBST(root->left);
    printBST(root->right);
}

// Main function
int main() {
    int nodes[] = {10, 5, 15, 3, 7, 12, 18};
    TreeNode* root = nullptr;
    // Inserting values in the binary search tree
    for (int value : nodes) {
        root = insert(root, value);
    }

    cout << "Print Binary Search Tree: ";
    printBST(root);
    
    int low = 7, high = 15;
    cout << "\nSum Of range node elements of tree: " << rangeSumBST(root,low,high);
    return 0;
}

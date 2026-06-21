// Insert into a Binary Search Tree Algorithm Implementation In C++
// Time Complexity: O(n)
// Space Complexity: O(h)
#include<iostream>
using namespace std;

// Node class of BST
class TreeNode {
    // Public Access Modifier
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    // Parameterized Constructor
    TreeNode(int val) {
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// Function to insert a nodes of BST
TreeNode* insert(TreeNode* root,int val) {
    if(root == nullptr) {
        return new TreeNode(val);
    }
    // Recursive Function
    if(root->val > val) {
        // Left Subtree
        root->left=insert(root->left,val);
    }
    if(root->val < val) {
        // Right Subtree
        root->right=insert(root->right,val);
    }
    return root;
}

// Function to perform the in-order traversal
void inOrder(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    // recursive function
    inOrder(root->left); // Left Subtree
    cout<<root->val<<" ";
    inOrder(root->right); // Right Subtree
}

// Main function
int main() {
    int values[]={5,3,6,2,4,7};
    TreeNode* root=nullptr;
    for(int num:values) {
        root=insert(root,num);
    }
    
    cout<<"In-Order Traversal: ";
    inOrder(root);
    return 0;
}



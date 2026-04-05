// Root to Leaf Path in a Binary Search Tree (BST) Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Node class For Binary Search Tree
class Node {
    // Public Access Specifier
    public:
    // Data members
    int data;
    Node* left;
    Node* right;
    // Parameterized Constructor
    Node(int value) {
        data=value;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// Function to insert the value in the Binary Search Tree
Node* insert(Node* root, int value) {
    if(root == nullptr) {
        return new Node(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform the pre order traversal
void preOrder(Node* root) {
    if(root == nullptr) return;
    cout<<root->data<<" ";
    // Recursive calls for left and right subtrees
    preOrder(root->left);
    preOrder(root->right);
}

// Function to print root to leaf paths in a binary tree
void printPath(vector<int>& path) {
    for(int num:path) {
        cout<<num<<"->";
    }
    cout<<"nullptr"<<endl;
}

// Function to find the root to leaf paths in a binary tree
void rootToLeaf(Node* root,vector<int>& path) {
    if(root == nullptr) return;
    // Add the current node to the path
    path.push_back(root->data);
    // If it's a leaf node, print the path
    if(root->left == nullptr && root->right == nullptr) {
        printPath(path);
    } else {
        // Recursive calls for left and right subtrees
        rootToLeaf(root->left, path);
        rootToLeaf(root->right, path);
    }
    // Backtrack: remove the current node from the path
    path.pop_back();
}

// Main function
int main() {
    vector<int> values={8,5,3,6,10,9,15,11,14};
    Node* root = nullptr;
    for(int value:values) {
        root = insert(root, value);
    }
    cout<<"Pre-order Traversal of the Binary Search Tree: ";
    preOrder(root);
    cout<<endl<<"Root to Leaf Paths in the Binary Search Tree: "<<endl;
    vector<int> path;
    rootToLeaf(root, path);
    return 0;
}

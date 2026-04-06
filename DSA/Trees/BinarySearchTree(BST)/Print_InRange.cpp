// Print All Nodes In A Given Range Algorithm Implementation In C++
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

// Function to insert values in the binary search tree
Node* insert(Node* root,int value) {
    if(root == nullptr) {
        return new Node(value);
    }
    // Recursion to insert the value in the left or right subtree based on the value
    if(value < root->data) {
        root->left=insert(root->left,value);
    }
    else {
        root->right=insert(root->right,value);
    }
    return root;
}

// Function to print all nodes in a given range
void printInRange(Node* root,int low,int high) {
    if(root == nullptr) return;
    // If the current node's value is greater than low, then there might be nodes in the left subtree that are in the range
    if(root->data > low) {
        printInRange(root->left,low,high);
    }
    // If the current node's value is within the range, print it
    if(root->data >= low && root->data <= high) {
        cout<<root->data<<" ";
    }
    // If the current node's value is less than high, then there might be nodes in the right subtree that are in the range
    if(root->data < high) {
        printInRange(root->right,low,high);
    }
}

// Function to perform the pre order traversal
void preOrder(Node* root) {
    if(root == nullptr) return;
    cout<<root->data<<" ";
    // Recursive calls for left and right subtrees
    preOrder(root->left);
    preOrder(root->right);
}

// Main function
int main() {
    int nodes[]={10,5,15,3,7,12,18};
    Node* root=nullptr;
    // Inserting values in the binary search tree
    for(int value:nodes) {
        root=insert(root,value);
    }
    cout<<"Pre Order Traversal of the Binary Search Tree: ";
    preOrder(root);
    int low=5,high=15;
    cout<<"\nNodes in the range ["<<low<<","<<high<<"] are: ";
    printInRange(root,low,high);
    return 0;
}

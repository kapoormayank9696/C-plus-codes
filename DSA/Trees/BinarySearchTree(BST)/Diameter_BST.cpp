// Diameter of Binary Search Tree(BST) Algorithm Implementation In C++
#include<iostream>
#include<algorithm>
using namespace std;
// Node class of Binary Search Tree(BST)
class Node {
    // Public Access Modifier
    public:
    int data;
    Node* left;
    Node* right;
    // Parameterized Constructor
    Node(int data) {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// Function to insert the nodes in Binary Search Tree(BST)
Node* insert(Node* root,int val) {
    if(root == nullptr) {
        return new Node(val);
    }
    // Recursive calls for left and right subtrees
    if(root->data > val) {
        // Left Subtree
        root->left=insert(root->left,val);
    }
    if(root->data < val) {
        // Right Subtree
        root->right=insert(root->right,val);
    }
    return root;
}

// Function to display the Binary Search Tree(BST)
void display(Node* root) {
    if(root == nullptr) {
        return;
    }
    // Recursive calls for left and right subtrees
    cout<<root->data<<" ";
    display(root->left); // Left Subtree
    display(root->right); // Right Subtree
}

class Solution {
    public:
    int diameter=0;
    // Function to find the height of Binary Search Tree(BST)
    int heightOfBST(Node* root) {
        if(root == nullptr) {
            return 0;
        }
        // Recursive calls for left and right subtrees
        int leftheight=heightOfBST(root->left); // Left Subtree
        int rightheight=heightOfBST(root->right); // Right Subtree
        diameter=max(diameter,leftheight+rightheight);
        return max(leftheight,rightheight)+1;
    }

    // Function to perform diameter algorithm
    int diameterOfNodes(Node* root) {
        heightOfBST(root);
        return diameter;
    }
};

// Main Function
int main() {
    int nums[]={5,3,6,2,4,7};
    Node* root=nullptr;
    for(int num:nums){
        root=insert(root,num);
    }
    cout<<"Display Binary Search Tree(BST): ";
    display(root);
    Solution obj;
    cout<<"\nDiameter of Binary Search Tree(BST): "<<obj.diameterOfNodes(root);
    return 0;
}


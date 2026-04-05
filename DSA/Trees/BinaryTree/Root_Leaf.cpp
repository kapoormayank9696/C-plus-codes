// Root to Leaf Path in a Binary Tree (BT) Algorithm Implementation In C++
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

class BinaryTree {
    public:
    int index=-1;
    Node* buildTree(int nodes[],int k) {
        index++;
        if(index >= k || nodes[index] == -1) {
            return nullptr;
        }
        // Create a new node with the current value
        Node* newNode=new Node(nodes[index]);
        // Recursive calls for left and right subtrees
        newNode->left=buildTree(nodes,k);
        newNode->right=buildTree(nodes,k);
        return newNode;
    }
};

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
    vector<int> values={8,5,3,-1,-1,6,-1,-1,10,9,-1,-1,15,-1,11,-1,14,-1,-1};
    BinaryTree tree;
    Node* root = tree.buildTree(values.data(), values.size());
    cout<<"Pre-order Traversal of the Binary Tree: ";
    preOrder(root);
    cout<<endl<<"Root to Leaf Paths in the Binary Tree: "<<endl;
    vector<int> path;
    rootToLeaf(root, path);
    return 0;
}



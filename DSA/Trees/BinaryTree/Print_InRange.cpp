// Print In Range All Nodes In A Binary Tree (BT) Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;
// Node class For Binary Tree
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

// class for Binary Tree
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
    BinaryTree bt;
    int nodes[]={10,5,3,-1,-1,7,-1,-1,15,12,-1,-1,18,-1,-1};
    Node* root=bt.buildTree(nodes,15);
    cout<<"Pre Order Traversal: ";
    preOrder(root);
    cout<<endl;
    int low=6,high=13;
    cout<<"Nodes in the range ["<<low<<","<<high<<"]: ";
    printInRange(root,low,high);
    return 0;
}

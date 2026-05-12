// Construct Binary Tree from Preorder and Inorder Traversal
#include<iostream>
#include<vector>
using namespace std;
// Class Of Node
class Node {
    // Public Access Specifier
    public:
    // Data Members
    int data;
    Node* left;
    Node* right;
    // Parameterized Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class Of Binary Tree
class BinaryTree {
    // Public Access Specifier
    public:
    int index=-1;
    Node* buildTree(int nodes[]) {
        index++;
        if(nodes[index] == -1) {
            return nullptr;
        }
        Node* newNode = new Node(nodes[index]);
        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);
        return newNode;
    }
};

// Function to Print Preorder Traversal
void Preorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Main Function
int main() {
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree;
    Node* root = tree.buildTree(nodes);
    cout << "Root of Binary Tree(BT) is: " << root->data << endl;
    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;
    return 0;
}

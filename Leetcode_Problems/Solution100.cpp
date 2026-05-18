// LeetCode Problem 100: Same Tree
#include <iostream>
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

// Function to print the binary tree 
void printTree(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

// Function to check if two binary trees are the same
bool isSameTree(Node* p, Node* q) {
    if(p == nullptr && q == nullptr) {
        return true;
    }
    if(p == nullptr || q == nullptr) {
        return false;
    }
    if(p->data != q->data) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Main function
int main() {
    int values1[] = {1, 2, 3};
    int k = sizeof(values1) / sizeof(values1[0]);
    int values2[] = {1, 2, 3};
    int k1 = sizeof(values2) / sizeof(values2[0]);
    BinaryTree tree1, tree2;
    Node* root1 = tree1.buildTree(values1, k);
    Node* root2 = tree2.buildTree(values2, k1);
    cout << "Tree 1: ";
    printTree(root1);
    cout << "\nTree 2: ";
    printTree(root2);
    cout << "\nAre the two trees the same? " << (isSameTree(root1, root2) ? "Yes" : "No") << endl;
    return 0;
}

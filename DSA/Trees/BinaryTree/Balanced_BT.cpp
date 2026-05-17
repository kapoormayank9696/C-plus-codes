// Balanced Binary Tree Check Algorithm Implementation In C++
#include <iostream>
#include <cmath>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
public:

    Node* insert(Node* root, int data) {

        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }

        return root;
    }
};

// Preorder traversal
void print(Node* root) {

    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    print(root->left);
    print(root->right);
}

// Height checking
int checkHeight(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = checkHeight(root->left);

    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight(root->right);

    if (rightHeight == -1) {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

// Balanced tree check
bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

// Main
int main() {

    int nums[] = {9, 3, 20, 15, 7};

    Node* root = nullptr;

    BinaryTree tree;

    for (int num : nums) {
        root = tree.insert(root, num);
    }

    cout << "Preorder Traversal: ";
    print(root);

    cout << "\nIs Balanced? "
         << (isBalanced(root) ? "Yes" : "No");

    return 0;
}
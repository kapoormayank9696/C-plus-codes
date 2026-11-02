// LeetCode Problem 235 : Lowest Common Ancestor of a Binary Search Tree
#include <iostream>
#include <vector>
using namespace std;

// Node class of Binary Search Tree
class TreeNode {
    public:

    // Data Members
    int data;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Insert nodes
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Display BST in preorder
void display(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

// Find node by value
TreeNode* search(TreeNode* root, int val) {
    if (root == nullptr || root->data == val) {
        return root;
    }

    if (val < root->data) {
        return search(root->left, val);
    }

    return search(root->right, val);
}

// Find Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || p == nullptr || q == nullptr) {
        return nullptr;
    }

    if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

// Main function
int main() {
    TreeNode *root = nullptr;

    vector<int> values = {6, 2, 8, 0, 4, 7, 9, 3, 5};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Preorder Traversal: ";
    display(root);

    // Find p and q nodes
    TreeNode* p = search(root, 2);
    TreeNode* q = search(root, 8);

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != nullptr) {
        cout << "\nLowest Common Ancestor: " << lca->data << endl;
    }

    return 0;
}
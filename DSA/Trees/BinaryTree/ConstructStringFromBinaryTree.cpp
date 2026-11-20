// Construct String from Binary Tree Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Node class
class TreeNode {
    public:

    int data;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Binary Tree class
class Solution {
    public:
    
    // Insert
    TreeNode* insert(TreeNode* root, int data) {
        if (root == nullptr) {
            return new TreeNode(data);
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }

        return root;
    }

    // Construct String From Binary Tree
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string str = to_string(root->data);

        // Left Subtree
        if (root->left != nullptr) {
            str += "(";
            str += tree2str(root->left);
            str += ")";
        }
        else if (root->right != nullptr) {
            str += "()";
        }

        // Right Subtree
        if (root->right != nullptr) {
            str += "(";
            str += tree2str(root->right);
            str += ")";
        }
        return str;
    }

    // Preorder traversal
    void print(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        cout << root->data << " ";
        print(root->left);
        print(root->right);
    }
};

// Main function
int main() {
    Solution sol;

    TreeNode* root = nullptr;

    // Creating Binary Tree
    root = sol.insert(root, 1);
    root = sol.insert(root, 2);
    root = sol.insert(root, 3);
    root = sol.insert(root, 4);

    // Preorder Traversal
    cout << "Preorder Traversal: ";
    sol.print(root);

    // Construct String
    cout << "\nConstructed String: " << sol.tree2str(root) << endl;

    return 0;
}

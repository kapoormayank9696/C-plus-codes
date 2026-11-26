// LeetCode Problem 814 : Binary Tree Pruning
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TreeNode Class
class TreeNode {
    // Public Access Specifier
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Solution Class
class Solution {
    public:
    int index = -1;

    // Build Tree Function
    TreeNode* buildTree(vector<int> &nodes) {
        index++;
        if (index >= nodes.size() || nodes[index] == -1) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(nodes[index]);

        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);

        return newNode;
    }

    // Function to check Tree Root Equals Sum of Children
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }

        return root;
    }

    // Display Tree Function
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // Recursive Function
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

int main() {
    Solution sol;

    vector<int> nodes = {1, -1, 0, 0, -1, -1, 1, -1, -1};
    TreeNode* root = sol.buildTree(nodes);

    cout << "Before Pruning: ";
    sol.inorder(root);
    cout << endl;

    root = sol.pruneTree(root);

    cout << "After Pruning: ";
    sol.inorder(root);
    cout << endl;
    return 0;
}

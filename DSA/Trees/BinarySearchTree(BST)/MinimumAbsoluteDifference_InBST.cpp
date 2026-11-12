// Minimum Absolute Difference in BST Algorithm Implementation In C++
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// TreeNode Class
class TreeNode {
    public:

    // Data Members
    int val;
    TreeNode *left;
    TreeNode *right;

    // Parameterized Constructor
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
    public:
    int min = INT_MAX;
    TreeNode *prev = nullptr;

    // Insert Function to insert a new node in BST
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insert(root->left, val);
        }
        else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    // Function to get the minimum absolute difference in BST
    int getMinimumDifference(TreeNode* root) {
        findDifference(root);
        return min;
    }

    // Inorder Traversal to find the minimum absolute difference
    void findDifference(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        findDifference(root->left);

        if (prev != nullptr) {
            min = std::min(min, root->val - prev->val);
        }

        prev = root;

        findDifference(root->right);
    }

    // Display Function
    void display(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }
};

// Main function
int main() {
    Solution sol;

    int values[] = {4, 2, 6, 1, 3};
    int n = sizeof(values) / sizeof(values[0]);

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        root = sol.insert(root, values[i]);
    }

    cout << "Print BST : ";
    sol.display(root);

    cout << "\nMinimum Difference Between BST Tree Nodes: "
         << sol.getMinimumDifference(root);

    return 0;
}

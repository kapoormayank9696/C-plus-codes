// LeetCode Problem 2331 : Evaluate Boolean Binary Tree
#include <iostream>
using namespace std;

// TreeNode class
class TreeNode {
    // Public Specifier
    public:

    int val;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Solution class
class Solution {
    public:

    // Evaluate Tree Function
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr || root->right == nullptr) {
            return root->val == 1;
        }

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        // Or Operation
        if (root->val == 2) {
            return left || right;
        }

        // And Operation
        return left && right;
    }
};

// Main function
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);

    // Creating Solution Object
    Solution sol;

    // Evaluate Boolean Binary Tree
    bool result = sol.evaluateTree(root);

    cout << "Evaluation Result: " << boolalpha << result << endl;

    // Free allocated memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

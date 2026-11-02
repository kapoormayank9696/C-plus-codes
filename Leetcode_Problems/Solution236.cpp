// LeetCode Problem 236 : Lowest Common Ancestor of a Binary Tree
#include <iostream>
#include <vector>
using namespace std;

// Node class for the binary tree
class TreeNode {

    // Public Specifier
    public:
    // Data Members
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

// Class Solution
class Solution {

    // Public Specifier
    public:

    // Data Member
    int index = -1;

    // Build Binary Tree
    TreeNode* buildTree(vector<int> &nums) {
        index++;
        if (index >= nums.size() || nums[index] == -1) {
            return nullptr;
        }

        // Create a new node with the current value
        TreeNode* node = new TreeNode(nums[index]);

        // Recursively build the left and right subtrees
        node->left = buildTree(nums);
        node->right = buildTree(nums);

        return node;
    }

    // Function to find the lowest common ancestor of two nodes in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return (left != nullptr) ? left : right;
    }

    // Function to display the binary tree in preorder
    void display(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        cout << root->val << " ";
        display(root->left);
        display(root->right);
    }
};

// Main function
int main() {
    Solution solution;
    vector<int> nums = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
    TreeNode* root = solution.buildTree(nums);
    cout << "Preorder Traversal: ";
    solution.display(root);

    // Find p and q nodes
    TreeNode* p = root->left;  // Node with value 5
    TreeNode* q = root->right; // Node with value 1

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        cout << "\nLowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    }
    else {
        cout << "\nLowest Common Ancestor not found." << endl;
    }
    return 0;
}

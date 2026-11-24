// Second Minimum Node In a Binary Tree Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TreeNode Class
class TreeNode {
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

    // Function to find second minimum value
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr || root->left == nullptr) {
            return -1;
        }

        int l = (root->left->val == root->val) ? findSecondMinimumValue(root->left) : root->left->val;

        int r = (root->right->val == root->val) ? findSecondMinimumValue(root->right) : root->right->val;

        return (l == -1 || r == -1) ? max(l, r) : min(l, r);
    }

    // Display Function
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

// Main Function
int main() {
    Solution sol;

    vector<int> nodes = {
        2, 2, -1, -1, 5, 5, -1, -1, 7, -1, -1};

    TreeNode* root = sol.buildTree(nodes);

    cout << "Inorder Traversal: ";
    sol.inorder(root);

    cout << endl;
    cout << "Second Minimum Value: " << sol.findSecondMinimumValue(root);
    return 0;
}

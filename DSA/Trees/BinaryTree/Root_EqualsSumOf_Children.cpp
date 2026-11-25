// Root Equals Sum of Children Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TreeNode Class
class TreeNode {
    // Public Access Specifier
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

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
        if (index >= nodes.size() || nodes[index] == -1){
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(nodes[index]);

        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);

        return newNode;
    }

    // Function to check Tree Root Equals Sum of Children
    bool checkTree(TreeNode* root) {
        return root->val == root->right->val + root->left->val;
    }

    // Display Tree Function
    void inorder(TreeNode* root) {
        if(root == nullptr)  {
            return;
        }
        // Recursive Function
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

// Main function
int main() {
    Solution sol;

    vector<int> nodes = {10, 4, -1, -1, 6, -1, -1};
    TreeNode* root = sol.buildTree(nodes);

    cout << "Inorder Traversal: ";
    sol.inorder(root);

    cout << endl;
    cout << "Root Equals Sum of Children: " << boolalpha << sol.checkTree(root) << endl;
    return 0;
}

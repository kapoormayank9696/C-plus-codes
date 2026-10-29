// LeetCode Problem 513: Find Bottom Left Tree 
#include <iostream>
using namespace std;

// Node class of Binary Tree(BT)
class TreeNode {
    // Public Access Modifier And Data Members
    public:

    int val;
    // Pointer To Left And Right Child Of Node
    TreeNode *left;
    TreeNode *right;

    // Parameterized Constructor
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Solution Class
class Solution {
    public:
    int maxHeight = -1;
    int result = 0;
    int index = -1;

    TreeNode *buildTree(int nodes[], int k) {
        index++;
        if (index >= k || nodes[index] == -1) {
            return nullptr;
        }
        // Creating New Node
        TreeNode *newNode = new TreeNode(nodes[index]);
        // Recursive Function
        newNode->left = buildTree(nodes, k);  // for left child of Binary Tree(BT)
        newNode->right = buildTree(nodes, k); // for right child of Binary Tree(BT)
        return newNode;
    }

    // PreOrder Method Work
    void preOrder(TreeNode *root, int height) {
        if (root == nullptr)
            return;

        if (height > maxHeight) {
            maxHeight = height;
            result = root->val;
        }

        preOrder(root->left, height + 1);
        preOrder(root->right, height + 1);
    }

    // Find Bottom Left Value Function
    int findBottomLeftValue(TreeNode *root) {
        preOrder(root, 0);
        return result;
    }

    // Function to perform the pre order traversal
    void preOrder(TreeNode *root) {
        if (root == nullptr)
            return;
        cout << root->val << " ";
        // Recursive calls for left and right subtrees
        preOrder(root->left);
        preOrder(root->right);
    }
};

// Main function
int main() {
    Solution sol;
    int nodes[] = {10,
                   5, 3, -1, -1, 7, -1, -1,
                   15, 12, -1, -1, 18, -1, -1};
    int k = sizeof(nodes) / sizeof(nodes[0]);

    TreeNode *root = sol.buildTree(nodes, k);
    cout << "Pre Order Traversal of the Binary Search Tree: ";
    sol.preOrder(root);

    cout << "\nBottom Left Value Of Binary Tree: " << sol.findBottomLeftValue(root);
    return 0;
}

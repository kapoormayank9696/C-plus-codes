// LeetCode Problem 538: Convert BST to Greater Tree
#include <iostream>
using namespace std;

// Binary Tree Class
class TreeNode {
    // Public Specifier
    public:

    // Data Members
    int val;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// Solution Class
class Solution {
    public:

    int index = -1;
    int sum = 0;

    // Insert
    TreeNode* insert(int nums[], int size) {
        index++;

        if (index >= size || nums[index] == -1) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(nums[index]);
        newNode->left = insert(nums, size);
        newNode->right = insert(nums, size);

        return newNode;
    }

    // Function to convert BST to Greater Tree
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        // Recursive call to the right subtree
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }

    // Display Binary Tree
    void display(TreeNode* root) {
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
    int nums[] = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    int size = sizeof(nums) / sizeof(nums[0]);
    TreeNode* root = solution.insert(nums, size);

    cout << "Original Binary Search Tree (BST): ";
    solution.display(root);
    cout << endl;

    TreeNode* newRoot = solution.convertBST(root);
    cout << "Converted Greater Tree: ";
    solution.display(newRoot);
    return 0;
}

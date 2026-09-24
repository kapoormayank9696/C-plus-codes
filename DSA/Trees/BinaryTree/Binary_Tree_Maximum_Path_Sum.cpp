
#include<iostream>
using namespace std;

// Binary Tree Node class
class TreeNode {

    // Public Access Specifier
    public:

    // Data Members
    int val;
    TreeNode* left;
    TreeNode* right;

    // Parameterized Constructor
    TreeNode(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Class to find the maximum path sum in a binary tree
class Solution {
    public:
    int inde = -1;

    // Function to build a binary tree from an array representation
    TreeNode* buildTree(int arr[], int n) {
        inde++;
        if(inde >= n || arr[inde] == -1) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(arr[inde]);
        node->left = buildTree(arr, n);
        node->right = buildTree(arr, n);
        return node;
    }

    int maxSum = INT_MIN; // Variable to store the maximum path sum

    // Function to calculate the maximum path sum
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

    // Depth-first search function to traverse the tree and calculate path sums
    int dfs(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }

        // Recursively calculate the maximum path sum for left and right subtrees
        int leftSum = max(0, dfs(node->left));
        int rightSum = max(0, dfs(node->right));

        // Sum of the current node value and the maximum path sums from left and right subtrees
        int currentPath = node->val + leftSum + rightSum;

        // Comparsion to update the maximum path sum found so far
        maxSum = max(maxSum, currentPath);

        // Return the maximum path sum including the current node and one of its subtrees
        return node->val + max(leftSum, rightSum);
    }
};

// Main function
int main() {
    Solution solution;
    int arr[] = {-10, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    TreeNode* root = solution.buildTree(arr, sizeof(arr)/sizeof(arr[0]));
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;    
    return 0;
}

// LeetCode Problem 113: Path Sum II
#include <iostream>
#include <vector>
using namespace std;

// TreeNode class
class TreeNode {
    // Public Specifier
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

// Solution Class
class Solution {
    // Public Specifier
    public:
    int index = -1;

    // Insert
    TreeNode *insert(int nums[], int n) {
        index++;
        if (index >= n || nums[index] == -1) {
            return nullptr;
        }
        TreeNode *newNode = new TreeNode(nums[index]);

        // Recursive Function
        newNode->left = insert(nums, n);
        newNode->right = insert(nums, n);
        return newNode;
    }

    // Function to help the Path Sum II
    void solve(TreeNode *root, int targetSum, vector<vector<int>> &result, vector<int> &list) {
        if (root == nullptr) {
            return;
        }
        list.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                result.push_back(list);
            }
        }
        else {
            solve(root->left, targetSum - root->val, result, list);
            solve(root->right, targetSum - root->val, result, list);
        }
        list.pop_back();
    }

    // Function of Path Sum II
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        vector<int> list;
        solve(root, targetSum, result, list);
        return result;
    }

    // Print Binary Tree
    void printTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";

        // Recursively Function
        printTree(root->left);
        printTree(root->right);
    }
};

// Main function
int main() {
    int nums[] = {
        5, 4, 11, 7, -1, -1, 2, -1, -1,
        -1, 8, 13, -1, -1, 4, 5, -1, -1, 1, -1, -1};
    int n = sizeof(nums) / sizeof(nums[0]);
    Solution sol;

    TreeNode *root = sol.insert(nums, n);
    cout << "Print Original Binary Tree: ";
    sol.printTree(root);

    int targetSum = 22;
    vector<vector<int>> result = sol.pathSum(root, targetSum);

    cout << endl
         << "Paths with sum " << targetSum << ":" << endl;

    for (const vector<int> &path : result) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}

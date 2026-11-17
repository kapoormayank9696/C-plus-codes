// Binary Tree Tilt Algorithm Implementation In C++
#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
using namespace std;

// TreeNode class
class TreeNode {
    // Public Specifier
    public:

    // Data Members
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
    int index = -1;
    int result = 0;

    // Insert Function to Build Binary Tree
    TreeNode* insert(vector<int>& nums) {
        index++;

        if (index >= nums.size() || nums[index] == -1) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(nums[index]);

        root->left = insert(nums);
        root->right = insert(nums);

        return root;
    }

    // Binary Tree Tilt Function
    int findTilt(TreeNode* root) {
        result = 0;
        postOrder(root);
        return result;
    }

    // Post Order Function
    int postOrder(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);

        result = result + abs(left - right);
        return left + right + root->val;
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
    Solution solution;

    vector<int> nums = {4, 2, 9, 3, 5};

    TreeNode* root = solution.insert(nums);

    // Display Binary Tree
    cout << "Inorder Traversal: ";
    solution.display(root);

    // Find Binary Tree Tilt
    cout << "\nBinary Tree Tilt: "
         << solution.findTilt(root) << endl;
    return 0;
}

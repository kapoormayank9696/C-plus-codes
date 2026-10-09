// Reverse Odd Levels of Binary Tree Algorithm Implementation In C++
#include <iostream>
#include <queue>
using namespace std;

// TreeNode Class
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

// Solution Class
class Solution {
    public:
    
    int index = -1;

    // Insert into the binary tree from the given array
    TreeNode* insert(int arr[], int n) {
        index++;
        if (index >= n || arr[index] == -1) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(arr[index]);
        node->left = insert(arr, n);
        node->right = insert(arr, n);
        return node;
    }

    // Function to reverse the odd levels of a binary tree
    void reverseOddLevels(TreeNode* root) {
        if (!root) return;
        reverseOddLevelsHelper(root->left, root->right, 1);
    }

    // Depth-First Search
    void reverseOddLevelsHelper(TreeNode* left, TreeNode* right, int level) {
        if (left == nullptr || right == nullptr) return;

        // If the current level is odd, swap the values of the nodes
        if (level % 2 == 1) {
            swap(left->val, right->val);
        }

        // Recur for the next level
        reverseOddLevelsHelper(left->left, right->right, level + 1);
        reverseOddLevelsHelper(left->right, right->left, level + 1);
    }

    // Print the binary tree in level order
    void printLevelOrder(TreeNode* root) {
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            cout << q.front()->val << " ";
            TreeNode* node = q.front();
            q.pop();

            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    }
};

// Main function
int main() {
    int arr[] = {2, 3, 8, -1, -1, 13, -1, -1, 5, 21, -1, -1, 34, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution sol;

    TreeNode* root = sol.insert(arr, n);
    cout << "Original Tree Level Order: ";
    sol.printLevelOrder(root);
    cout << endl;

    sol.reverseOddLevels(root);
    cout << "Tree After Reversing Odd Levels: ";
    sol.printLevelOrder(root);
    return 0;
}

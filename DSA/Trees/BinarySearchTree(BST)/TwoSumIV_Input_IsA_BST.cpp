// Two Sum IV - Input is a BST Algorithm Implementation In C++
#include <iostream>
#include <unordered_set>
using namespace std;

// TreeNode class
class TreeNode {
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
    
    // HashSet
    unordered_set<int> set;

    // Insert Operation
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Recursive Relation
        if (val < root->val) {
            root->left = insert(root->left, val);
        }
        else if (val > root->val) {
            root->right = insert(root->right, val);
        }

        return root;
    }

    // Find Target Operation
    bool findTarget(TreeNode* root, int k) {
        set.clear();
        return findTargetDFS(root, k);
    }

    // Recursive DFS Operation
    bool findTargetDFS(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }

        if (set.find(k - root->val) != set.end()) {
            return true;
        }

        set.insert(root->val);

        return findTargetDFS(root->right, k) ||
               findTargetDFS(root->left, k);
    }

    // Display Operation
    void display(TreeNode* root) {
        if (root != nullptr) {
            display(root->left);
            cout << root->val << " ";
            display(root->right);
        }
    }
};

// Main function
int main() {
    Solution sol;
    TreeNode* root = nullptr;
    int values[] = {5, 3, 6, 2, 4, 7};

    // Build BST
    for (int val : values) {
        root = sol.insert(root, val);
    }

    // Display BST
    cout << "Inorder Traversal: ";
    sol.display(root);

    // Find Target
    int k = 9;
    cout << "\nTarget Sum: " << k << endl;
    cout << "Two Sum Exists: " << boolalpha << sol.findTarget(root, k) << endl;

    return 0;
}

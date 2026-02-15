// LeetCode Problem 144: Binary Tree Preorder Traversal

#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode
class TreeNode {
    // Public Access Modifier And Data Members
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    // Parameterized Constructor
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// BinaryTree builder
class BinaryTree{
public:
    int index = -1;
    TreeNode* buildTree(int nodes[], int k){
        index++;
        if(index >= k || nodes[index] == -1){
            return nullptr;
        }
        // Creating New TreeNode
        TreeNode* newNode = new TreeNode(nodes[index]);
        // Recursive Function
        newNode->left = buildTree(nodes, k);   // left child
        newNode->right = buildTree(nodes, k);  // right child
        return newNode;
    }
};

// Solution class
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        buildTree(root, result);
        return result;
    }

private:
    void buildTree(TreeNode* root, vector<int>& list) {
        if (root == nullptr) return;
        list.push_back(root->val);          // Visit root
        buildTree(root->left, list);        // Visit left subtree
        buildTree(root->right, list);       // Visit right subtree
    }
};

// Main function
int main() {
    int nodes[] = {1, -1, 2, 3, -1, -1, -1};
    int k = sizeof(nodes) / sizeof(nodes[0]);
    BinaryTree bt;
    TreeNode* root = bt.buildTree(nodes, k);  // Build tree properly
    Solution sol;
    vector<int> preorder = sol.preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

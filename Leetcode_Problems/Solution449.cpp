// LeetCode Problem 449 : Serialize and Deserialize Binary Search Tree
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

// Binary Tree Node
class TreeNode {
    // Public Access Specifier
    public:

    // Data Members
    int val;
    TreeNode *left;
    TreeNode *right;

    // Parameterized Constructor
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    // Public Access Specifier
    public:

    // Function to insert the nodes in BST
    TreeNode *insert(TreeNode *root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        // Recursive Function
        if (root->val > val) {
            // Left Subtree
            root->left = insert(root->left, val);
        }
        else if (root->val < val) {
            // Right Subtree
            root->right = insert(root->right, val);
        }
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string str;
        preOrder(root, str);
        return str;
    }

    // Preorder Method
    void preOrder(TreeNode *root, string &str) {
        if (root == nullptr) {
            str += "#,";
            return;
        }

        str += to_string(root->val) + ",";

        preOrder(root->left, str);
        preOrder(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        queue<string> q;
        stringstream ss(data);
        string value;

        while (getline(ss, value, ',')) {
            q.push(value);
        }

        return buildTree(q);
    }

    // Build Tree Method
    TreeNode *buildTree(queue<string> &q) {
        if (q.empty()) {
            return nullptr;
        }

        string value = q.front();
        q.pop();

        if (value == "#") {
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(value));

        root->left = buildTree(q);
        root->right = buildTree(q);

        return root;
    }
};

// Main Function
int main() {

    Solution sol;

    vector<int> values = {
        1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    TreeNode *root = nullptr;
    for (int num : values) {
        root = sol.insert(root, num);
    }

    // Serialize
    string data = sol.serialize(root);

    cout << "Serialized Tree: " << data << endl;

    // Deserialize
    TreeNode *newRoot = sol.deserialize(data);

    // Serialize Again
    string result = sol.serialize(newRoot);

    cout << "Deserialized Tree: " << result << endl;

    cout << "Are both same? "
         << (data == result ? "true" : "false") << endl;

    return 0;
}

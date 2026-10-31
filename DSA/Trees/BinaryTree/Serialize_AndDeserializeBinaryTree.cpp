// Serialize and Deserialize Binary Tree Algorithm Implementation In C++
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
    TreeNode* left;
    TreeNode* right;

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
    int index = -1;

    // Insert nodes in Binary Tree
    TreeNode* insert(vector<int>& values) {
        index = -1;
        return createTree(values);
    }

    // Create Tree Method
    TreeNode* createTree(vector<int>& values) {
        index++;

        if (index >= values.size() || values[index] == -1) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(values[index]);

        newNode->left = createTree(values);
        newNode->right = createTree(values);

        return newNode;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        preOrder(root, str);
        return str;
    }

    // Preorder Method
    void preOrder(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "#,";
            return;
        }

        str += to_string(root->val) + ",";

        preOrder(root->left, str);
        preOrder(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
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
    TreeNode* buildTree(queue<string>& q) {
        if (q.empty()) {
            return nullptr;
        }

        string value = q.front();
        q.pop();

        if (value == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = buildTree(q);
        root->right = buildTree(q);

        return root;
    }
};

// Main Function
int main() {

    Solution sol;

    vector<int> values = {
        1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1
    };

    // Create Original Tree
    TreeNode* root = sol.insert(values);

    // Serialize
    string data = sol.serialize(root);

    cout << "Serialized Tree: " << data << endl;

    // Deserialize
    TreeNode* newRoot = sol.deserialize(data);

    // Serialize Again
    string result = sol.serialize(newRoot);

    cout << "Deserialized Tree: " << result << endl;

    cout << "Are both same? "
         << (data == result ? "true" : "false") << endl;

    return 0;
}

// Average of Levels in Binary Tree Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node class for the binary tree
class TreeNode {
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

// Class to insert nodes and calculate averages
class Solution {
    public:
    int index = -1;

    // Insert nodes in Binary Tree
    TreeNode *insert(vector<int>& values){
        index = -1;
        return createTree(values);
    }

    // Create Tree Method
    TreeNode *createTree(vector<int>& values) {
        index++;

        if (index >= values.size() || values[index] == -1) {
            return nullptr;
        }

        TreeNode *newNode = new TreeNode(values[index]);

        newNode->left = createTree(values);
        newNode->right = createTree(values);

        return newNode;
    }

    // Print Preorder Traversal
    void printPreOrder(TreeNode* root) {
        if (root != nullptr) {
            cout << root->val << " ";
            printPreOrder(root->left);
            printPreOrder(root->right);
        }
    }

    // Average Of Levels
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            double average = sum / size;
            result.push_back(average);
        }

        return result;
    }
};

// Main Function
int main() {
    // -1 represents null
    vector<int> values = {
        1, 2, 2, 3, -1, -1, 3, 4, -1, -1, 4};

    Solution tree;
    TreeNode* root = tree.insert(values);

    cout << "Pre-order Traversal of the Binary Tree: ";
    tree.printPreOrder(root);

    vector<double> averages = tree.averageOfLevels(root);

    cout << "\nAverage of Each Level: ";

    for (double average : averages) {
        cout << average << " ";
    }

    cout << endl;
    return 0;
}

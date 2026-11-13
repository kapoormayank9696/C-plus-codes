// LeetCode Problem 515 : Find Largest Value in Each Tree Row
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Binary Tree Class
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
    public:
    int index = -1;

    // Insert
    TreeNode* buildTree(int nodes[], int k) {
        index++;
        if (index >= k || nodes[index] == -1) {
            return nullptr;
        }

        // Creating New Node
        TreeNode *newNode = new TreeNode(nodes[index]);

        // Recursive Function
        newNode->left = buildTree(nodes, k);  // for left child of Binary Tree(BT)
        newNode->right = buildTree(nodes, k); // for right child of Binary Tree(BT)

        return newNode;
    }

    // Find Largest Value From Binary Tree
    vector<int> largestValues(TreeNode* root) {

        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int max = INT_MIN;

            for (int i = 0; i < size; i++) {

                TreeNode *temp = q.front();
                q.pop();

                max = std::max(max, temp->val);

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }

                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }

            result.push_back(max);
        }

        return result;
    }

    // Function to perform the pre order traversal
    void preOrder(TreeNode* root) {
        if (root == nullptr)
            return;
        cout << root->val << " ";
        // Recursive calls for left and right subtrees
        preOrder(root->left);
        preOrder(root->right);
    }
};

// Main fnction
int main() {
    Solution sol;

    int nodes[] = {
        1, 3, 5, -1, -1, 3, -1, -1,
        2, -1, 9, -1, -1};

    int k = sizeof(nodes) / sizeof(nodes[0]);

    TreeNode *root = sol.buildTree(nodes, k);

    cout << "Preorder Traversal: ";
    sol.preOrder(root);

    cout << "\nLargest Values in Each Tree Row: ";

    vector<int> result = sol.largestValues(root);

    for (int num : result) {

        cout << num << " ";
    }

    cout << endl;

    return 0;
}

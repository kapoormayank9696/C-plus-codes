// Maximum Level Sum of a Binary Tree Algorithm Implementation In C++
#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

// TreeNode class
class TreeNode {
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

    // Insert Function to Build Binary Tree
    TreeNode* insert(vector<int> &nums)
    {
        index++;

        if (index >= nums.size() || nums[index] == -1)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(nums[index]);

        root->left = insert(nums);
        root->right = insert(nums);

        return root;
    }

    // Maximum Level Sum
    int maxLevelSum(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        queue<TreeNode *> q;
        q.push(root);

        int level = 0;
        int bestLevel = 0;
        int max = INT_MIN;

        while (!q.empty())
        {
            int size = q.size();
            int sum = 0;
            level++;

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                sum = sum + temp->val;

                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }

                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }

            if (max < sum) {
                max = sum;
                bestLevel = level;
            }
        }

        return bestLevel;
    }

    // Display Operation
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

    vector<int> nums = {
        1, 7, 7, -1, -1, -8, -1, -1,
        0, -1, -1};

    TreeNode *root = solution.insert(nums);

    // Display Binary Tree
    cout << "Inorder Traversal: ";
    solution.display(root);

    // Maximum Level Sum
    cout << "\nMaximum Level Sum: "
         << solution.maxLevelSum(root) << endl;

    return 0;
}

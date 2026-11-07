// Binary Tree Cameras Algorithm Implementation In C++
#include <iostream>
#include <vector>
using namespace std;

// TreeNode Class
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Parameterized Constructor
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Solution Class
class Solution
{
public:
    int count = 0;
    int index = -1;

    // Insert Function to Build Binary Tree
    TreeNode *insert(vector<int> &nums)
    {
        index++;

        if (index >= nums.size() || nums[index] == -1)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(nums[index]);

        root->left = insert(nums);
        root->right = insert(nums);

        return root;
    }

    // Function to Count Minimum Number of Cameras
    int minCameraCover(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (dfs(root) == -1)
        {
            count++;
        }

        return count;
    }

    // Depth-First Search Function
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftCount = dfs(root->left);
        int rightCount = dfs(root->right);

        if (leftCount == -1 || rightCount == -1)
        {
            count++;
            return 1;
        }

        if (leftCount == 1 || rightCount == 1)
        {
            return 0;
        }

        return -1;
    }

    // Display Function
    void display(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }
};

// Main Function
int main()
{
    Solution solution;

    vector<int> nums = {0, 0, -1, -1, 0, -1, -1};

    TreeNode *root = solution.insert(nums);

    int camerasNeeded = solution.minCameraCover(root);

    cout << "Minimum number of cameras needed: "
         << camerasNeeded << endl;

    return 0;
}

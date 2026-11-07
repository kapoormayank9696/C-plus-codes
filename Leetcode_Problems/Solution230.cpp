// LeetCode Problem 230 : Kth Smallest Element in a BST
#include <iostream>
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
    int answer = 0;
    int count = 0;

    // Insert Function to Insert a Node in BST
    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < root->val)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }

        return root;
    }

    // Function to find the kth smallest element in a BST
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return answer;
    }

    // Inorder Traversal Function
    void inorder(TreeNode *root, int k)
    {
        if (root == nullptr)
            return;

        inorder(root->left, k);

        count++;

        if (count == k)
        {
            answer = root->val;
            return;
        }

        inorder(root->right, k);
    }

    // Display Function to Print the BST
    void display(TreeNode *root)
    {
        if (root == nullptr)
            return;

        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }
};

// Main Function
int main()
{
    Solution solution;
    TreeNode *root = nullptr;

    // Insert nodes into the BST
    int values[] = {5, 3, 6, 2, 4, 1};

    for (int val : values)
    {
        root = solution.insert(root, val);
    }

    // Display the BST
    cout << "Inorder Traversal of BST: ";
    solution.display(root);
    cout << endl;

    // Find the kth smallest element
    int k = 3;

    int kthSmallestElement = solution.kthSmallest(root, k);

    cout << k << "th smallest element in the BST is: "
         << kthSmallestElement << endl;

    return 0;
}
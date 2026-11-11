// LeetCode Problem 99: Recover Binary Search Tree
#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    TreeNode *insert(TreeNode *root, int data)
    {
        if (root == nullptr)
        {
            return new TreeNode(data);
        }

        if (data < root->val)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }

        return root;
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *prev = nullptr;

        helper(root, first, second, prev);

        if (first != nullptr && second != nullptr)
        {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }

    void helper(TreeNode *root, TreeNode *&first,
                TreeNode *&second, TreeNode *&prev)
    {

        if (root == nullptr)
        {
            return;
        }

        helper(root->left, first, second, prev);

        if (prev != nullptr && root->val < prev->val)
        {
            if (first == nullptr)
            {
                first = prev;
            }

            second = root;
        }

        prev = root;

        helper(root->right, first, second, prev);
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

int main()
{
    BST bst;
    TreeNode *root = nullptr;

    root = bst.insert(root, 3);
    root = bst.insert(root, 1);
    root = bst.insert(root, 4);

    root->left->right = new TreeNode(2);

    cout << "Inorder Traversal of the original BST: ";
    bst.inorder(root);
    cout << endl;

    bst.recoverTree(root);

    cout << "Inorder Traversal of the recovered BST: ";
    bst.inorder(root);

    return 0;
}

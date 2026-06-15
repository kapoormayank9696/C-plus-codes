// Check Path Sum Algorithm Implementation In C++
#include <iostream>
#include <vector>
using namespace std;

// Class of Binary Tree Node
class TreeNode {
    public:
    
    int data;
    TreeNode* left;
    TreeNode* right;
    
    // Parameterized Constructor
    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Class to Build the Binary Tree
class BinaryTree {
    public:
    int index = -1;
    
    TreeNode* BuildTree(TreeNode* &root, vector<int>& nodes) {
        index++;

        if (index >= nodes.size() || nodes[index] == -1) {
            return nullptr;
        }

        TreeNode* newRoot = new TreeNode(nodes[index]);

        newRoot->left = BuildTree(newRoot->left, nodes);
        newRoot->right = BuildTree(newRoot->right, nodes);

        return newRoot;
    }

    // Function to check the path sum in the binary tree
    bool checkPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return targetSum == root->data;
        }
        return checkPathSum(root->left, targetSum - root->data) || checkPathSum(root->right, targetSum - root->data);
    }

    // Function to display the Binary Tree
    void display(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        cout << root->data << " ";
        display(root->left);
        display(root->right);
    }
};


// Main function
int main() {
    BinaryTree bt;
    TreeNode* root = nullptr;
    vector<int> nodes = {5, 4, 11, 7, -1, -1, 2, -1, -1, -1, 8, 13, -1, -1, 4, -1, 1, -1, -1};
    root = bt.BuildTree(root, nodes);
    cout << "Binary Tree: ";
    bt.display(root);
    int targetSum = 22;
    cout << "\nPath with sum is " << targetSum << " exists in the binary tree: " << boolalpha << bt.checkPathSum(root, targetSum) << endl;
    return 0;
}


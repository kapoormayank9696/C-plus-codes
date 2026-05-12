// Construct Binary Tree from Preorder and Inorder Traversal
#include<iostream>
#include<vector>
#include<map>
using namespace std;
// Class Of Node
class TreeNode {
    // Public Access Specifier
    public:
    // Data Members
    int data;
    TreeNode* left;
    TreeNode* right;
    // Parameterized Constructor
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class Of Binary Tree
class BinaryTree {
    // Public Access Specifier
    public:
    map<int, int> inOrderMap;
    int index=-1;
    int preorderIndex=0;;
    TreeNode* buildTree(int nodes[]) {
        index++;
        if(nodes[index] == -1) {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(nodes[index]);
        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);
        return newNode;
    }

    // Function to return the root from selecting the root inOrder
    TreeNode* BuildTree(int inorder[],int preorder[],int n) {
        for(int i=0; i<n; i++) {
            inOrderMap[inorder[i]] = i;
        }
        TreeNode* root = BuildTrees(preorder, 0, n-1);
        return root;
    }

    // Function to build the tree from inorder to preorder
    TreeNode* BuildTrees(int preorder[],int start,int end) {
        if(start > end) {
            return nullptr;
        }
        int rootValue=preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        int inOrderIndex = inOrderMap[rootValue];
        // Recursive calls to build left and right subtrees
        root->left = BuildTrees(preorder, start, inOrderIndex - 1);
        root->right = BuildTrees(preorder, inOrderIndex + 1, end);
        return root;
    }
};

// Function to Print Preorder Traversal
void Preorder(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Main Function
int main() {
    int nodes[] = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    BinaryTree tree;
    TreeNode* root = tree.buildTree(nodes);
    cout << "Root of Binary Tree(BT) is: " << root->data << endl;
    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;
    int inOrder[]  = {9, 3, 15, 20, 7};
    int n = sizeof(inOrder) / sizeof(inOrder[0]);
    int preOrder[] = {3, 9, 20, 15, 7};
    TreeNode* newRoot = tree.BuildTree(inOrder, preOrder, n);
    cout << "Preorder Traversal of Constructed Binary Tree(BT) is: ";
    Preorder(newRoot);
    return 0;
}

// Construct Binary Tree from Postorder and Inorder Traversal

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
    int postorderIndex=0;
    
    // Function to build the binary tree from the given array
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
    TreeNode* BuildTree(int inorder[],int postorder[],int n) {
        for(int i=0; i<n; i++) {
            inOrderMap[inorder[i]] = i;
        }
        postorderIndex = n - 1;
        TreeNode* root = BuildTrees(postorder, 0, n-1);
        return root;
    }

    // Function to build the tree from inorder to postorder
    TreeNode* BuildTrees(int postorder[],int start,int end) {
        if(start > end) {
            return nullptr;
        }
        int rootValue=postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootValue);
        int inOrderIndex = inOrderMap[rootValue];
        // Recursive calls to build left and right subtrees
        root->right = BuildTrees(postorder, inOrderIndex + 1, end);
        root->left = BuildTrees(postorder, start, inOrderIndex - 1);
        return root;
    }
};

// Function to Print Binary Tree
void print(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

// Main Function
int main() {
    int nodes[] = {3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    BinaryTree tree;
    TreeNode* root = tree.buildTree(nodes);
    cout << "Root of Binary Tree(BT) is: " << root->data << endl;
    cout << "Print Traversal: ";
    print(root);
    cout << endl;
    int inOrder[]  = {9, 3, 15, 20, 7};
    int n = sizeof(inOrder) / sizeof(inOrder[0]);
    int postOrder[] = {9, 15, 7, 20, 3};
    TreeNode* newRoot = tree.BuildTree(inOrder, postOrder, n);
    cout << "Root of Constructed Binary Tree(BT) is: " << newRoot->data << endl;
    cout << "Print Traversal of Constructed Binary Tree(BT) is: ";
    print(newRoot);
    return 0;
}

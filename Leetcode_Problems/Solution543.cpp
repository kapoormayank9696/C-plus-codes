// LeetCode Problem 543: Diameter of Binary Tree
#include <iostream>
#include<algorithm>
using namespace std;

// Node class of Binary Tree(BT)
class TreeNode{
    // Public Access Modifier And Data Members
    public:
    int data;
    // Pointer To Left And Right Child Of Node
    TreeNode* left;
    TreeNode* right;
    // Parameterized Constructor
    TreeNode(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// class to find the root of Binary Tree(BT)
class BinaryTree{
    public:
    int index=-1;
    TreeNode* buildTree(int nodes[],int k){
        index++;
        if(index >= k || nodes[index] == -1){
            return nullptr;
        }
        // Creating New Node
        TreeNode* newNode =new TreeNode(nodes[index]);
        // Recursive Function
        newNode->left=buildTree(nodes,k); // for left child of Binary Tree(BT)
        newNode->right=buildTree(nodes,k); // for right child of Binary Tree(BT)
        return newNode;
    }
};

// Method to find Diameter Of Binary Tree(BT)
class Solution {
    public:
    int diameter = 0;
    // Method to find the Height of Binary Tree(BT) and 
    int height(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        diameter = max(diameter,leftHeight+rightHeight);
        return max(leftHeight,rightHeight)+1;
    }
    
    // Diameter of Binary Tree(BT)
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};

// Main function
int main(){
    int nodes[]={2,4,8,-1,-1,9,10,-1,-1,11,-1,-1,3,6,-1,-1,7,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree* tree=new BinaryTree();
    TreeNode* root=tree->buildTree(nodes,k);
    cout<<"Root of Binary Tree is: "<<root->data<<endl;
    Solution sol;
    sol.height(root);
    cout<<"Diameter Of Binary Tree is: "<<sol.diameter<<endl;
    return 0;
}

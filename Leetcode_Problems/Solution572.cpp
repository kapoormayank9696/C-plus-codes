// LeetCode Problem 572: Subtree of Another Tree
#include<iostream>
using namespace std;

// Node class of Binary Tree(BT)
class Node{
    // Public Access Modifier
    public:
    
    // Data Members
    int data;
    Node* left;
    Node* right;
    
    // Parameterized Constructor
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// Class to find the root of Binary Tree(BT)
class BinaryTree{
    public:
    int index=-1;
    Node* buildTree(int nodes[],int k){
        index++;
        if(index >= k || nodes[index] == -1){
            return nullptr;
        }
        Node* newNode =new Node(nodes[index]);
        // Recursive Function
        newNode->left=buildTree(nodes,k); // for left child of Binary Tree(BT)
        newNode->right=buildTree(nodes,k); // for right child of Binary Tree(BT)
        return newNode;
    }
};

// Method to check the two trees are identical or not
bool isIdentical(Node* root, Node * subRoot) {
    if(root == nullptr && subRoot == nullptr){
        return true;
    }
    if(root == nullptr || subRoot == nullptr){
        return false;
    }
    return isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right) && root->data == subRoot->data;
}

// Method to check the subRoot is subtree of root or not
bool isSubtree(Node* root, Node* subRoot) {
    if(subRoot == nullptr){
        return true;
    }
    if(root == nullptr){
        return false;
    }
    if(isIdentical(root,subRoot)){
        return true;
    }
    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}

// Main function
int main(){
    int nodes[]={3,4,1,-1,-1,2,-1,-1,5,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    int subNodes[]={4,1,-1,-1,2,-1,-1};
    int subK=sizeof(subNodes)/sizeof(subNodes[0]);
    BinaryTree subTree;
    Node* subRoot=subTree.buildTree(subNodes,subK);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    cout<<"Root of Subroot Binary Tree(BT): "<<subRoot->data<<endl;
    cout<<"SubTree of Binary Tree(BT) is: "<<(isSubtree(root,subRoot)?"true":"false")<<endl;
    return 0;
}



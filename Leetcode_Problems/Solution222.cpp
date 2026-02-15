// LeetCode Problem 222: Count Nodes Tree Nodes
#include<iostream>
#include<queue>
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
        newNode->left=buildTree(nodes,k);
        newNode->right=buildTree(nodes,k);
        return newNode;
    }
};

// Method to traverse the level order(DFS)
int CountOfNodes(Node* root){
    if(root == nullptr){
        return 0;
    }
    int leftNodes=CountOfNodes(root->left);
    int rightNodes=CountOfNodes(root->right);
    return leftNodes+rightNodes+1;
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    cout<<"Count Numbers Of Node From Binary Tree(BT): "<<CountOfNodes(root)<<endl;
    return 0;
}

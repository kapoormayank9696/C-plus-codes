// Sum Of Nodes Algorithm Implementation In C++
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
        newNode->left=buildTree(nodes,k); // for left child of Binary Tree(BT)
        newNode->right=buildTree(nodes,k); // for right child of Binary Tree(BT)
        return newNode;
    }
};

// Method to Sum of Nodes
int SumOfNodes(Node* root){
    if(root == nullptr){
        return 0;
    }
    int leftNodes=SumOfNodes(root->left);
    int rightNodes=SumOfNodes(root->right);
    return leftNodes+rightNodes+root->data;
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    cout<<"Sum Of Nodes From Binary Tree(BT): "<<SumOfNodes(root)<<endl;
    return 0;
}

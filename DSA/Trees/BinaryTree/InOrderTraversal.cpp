// InOrder Traversal Algorithms Implementation In C++

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

// BinaryTree builder
class BinaryTree{
    public:
    int index=-1;
    Node* buildTree(int nodes[]) {
        index++;
        if(nodes[index] == -1){
            return nullptr;
        }
        Node* newNode =new Node(nodes[index]);
        newNode->left=buildTree(nodes);
        newNode->right=buildTree(nodes);
        return newNode;
    }
};

void Inorder(Node* root){
    if(root == nullptr){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

// Main function
int main(){
    // Array of node which carry the binary tree nodes element
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    BinaryTree tree;
    Node* root=tree.buildTree(nodes);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    cout<<"Inorder Traversal: ";
    Inorder(root);
    return 0;
}

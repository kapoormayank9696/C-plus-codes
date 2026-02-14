// Minimum Depth Of Node Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Node class of Binary Tree(BT)
class Node{
    // Public Access Modifier And Data Members
    public:
    int data;
    // Pointer To Left And Right Child Of Node
    Node* left;
    Node* right;
    // Parameterized Constructor
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// class to find the root of Binary Tree(BT)
class BinaryTree{
    public:
    int index=-1;
    Node* buildTree(int nodes[],int k){
        index++;
        if(index >= k || nodes[index] == -1){
            return nullptr;
        }
        // Creating New Node
        Node* newNode =new Node(nodes[index]);
        // Recursive Function
        newNode->left=buildTree(nodes,k); // for left child of Binary Tree(BT)
        newNode->right=buildTree(nodes,k); // for right child of Binary Tree(BT)
        return newNode;
    }
};

// Method to find the Maximum Depth of Binary Tree(BT) 
int HeightOfNodes(Node* root){
    if(root == nullptr){
        return 0;
    }
    // Recursive function
    int leftHeight=HeightOfNodes(root->left);
    int rightHeight=HeightOfNodes(root->right);
    
    if(leftHeight == 0){
        return rightHeight+1;
    }
    if(rightHeight == 0){
        return leftHeight+1;
    }
    return min(leftHeight,rightHeight)+1;
}

// Main function
int main(){
    int nodes[]={2,4,8,-1,-1,9,10,-1,-1,11,-1,-1,3,6,-1,-1,7,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree* tree=new BinaryTree();
    Node* root=tree->buildTree(nodes,k);
    cout<<"Root of Binary Tree is: "<<root->data<<endl;
    HeightOfNodes(root);
    cout<<"Minimum Depth Of Binary Tree is: "<<HeightOfNodes(root)<<endl;
    return 0;
}


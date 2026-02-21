// Right Side View of Binary Tree Algorithm Implementation In C++
#include<iostream>
#include<vector>
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
        // Create a new node with the current index value
        Node* newNode=new Node(nodes[index]);
        // Recursive calls to build the left and right subtrees
        newNode->left=buildTree(nodes,k);
        newNode->right=buildTree(nodes,k);
        return newNode;
    }
};

// Method to find the right side view of a binary tree
void rightSideView(Node* root, vector<int>& view, int level){
    if(root == nullptr){
        return;
    }
    if(level == view.size()){
        view.push_back(root->data);
    }
    rightSideView(root->right, view, level + 1);
    rightSideView(root->left, view, level + 1);
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    cout<<"Root of the Binary Tree: "<<root->data<<endl;
    vector<int> view;
    rightSideView(root, view, 0);
    cout<<"Right Side View of the Binary Tree: ";
    for(int val : view){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}


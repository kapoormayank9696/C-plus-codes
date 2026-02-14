// Level Order Traversal Algorithm Implementation In C++
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
        if(nodes[index] == -1){
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
void levelOrder(Node* root){
    if(root == nullptr){
        return;
    }
    queue<Node*> q;
    // Push Operation
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        // Store the queue first element
        Node* currentNode=q.front();
        // Remove the queue first element
        q.pop();
        if(currentNode == nullptr){
            cout<<"\n";
            // Check queue is empty or not
            if(q.empty()){
                break;
            }else{
                q.push(nullptr);
            }
        }else{
            cout<<currentNode->data<<" ";
            if(currentNode->left != nullptr){
                q.push(currentNode->left);
            }
            if(currentNode->right != nullptr){
                q.push(currentNode->right);
            }
        }
    }    
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    cout<<"Level Order Traversal of Binary Tree: "<<endl;
    levelOrder(root);
    return 0;
}

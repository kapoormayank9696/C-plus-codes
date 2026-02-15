// LeetCode Problem 102: Binary Tree Level Order Traversal
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Node class of Binary Tree(BT)
class TreeNode{
    // Public Access Modifier
    public:
    
    // Data Members
    int data;
    TreeNode* left;
    TreeNode* right;
    
    // Parameterized Constructor
    TreeNode(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// Class to find the root of Binary Tree(BT)
class BinaryTree{
    public:
    int index=-1;
    TreeNode* buildTree(int nodes[],int k){
        index++;
        if(nodes[index] == -1){
            return nullptr;
        }
        TreeNode* newNode =new TreeNode(nodes[index]);
        // Recursive Function
        newNode->left=buildTree(nodes,k);
        newNode->right=buildTree(nodes,k);
        return newNode;
    }
};

// Method to traverse the level order(DFS)
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    queue<TreeNode*> q;
    // Push Operation
    q.push(root);
    q.push(nullptr);
        vector<int> currentLevel; // To store the current level nodes
        while (!q.empty())
        {
            // Store the queue first element
            TreeNode* currentNode=q.front();
            // Remove the queue first element
            q.pop();
            if(currentNode == nullptr){
                result.push_back(currentLevel); // Add current level to result
                currentLevel.clear(); // Clear for next level
                // Check queue is empty or not
                if(!q.empty()){
                    q.push(nullptr);
                }  
            }else{
                currentLevel.push_back(currentNode->data); // Add current node to current level
                if(currentNode->left != nullptr){
                    q.push(currentNode->left);
                }
                if(currentNode->right != nullptr){
                    q.push(currentNode->right);
                }
            }
        }
    return result;
}

// Function to print the level order traversal result
void printLevelOrder(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl; // New line after each level
    }
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    TreeNode* root=tree.buildTree(nodes,k);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    vector<vector<int>> result=levelOrder(root);
    cout<<"Level Order Traversal of Binary Tree: "<<endl;
    printLevelOrder(result);
    return 0;
}

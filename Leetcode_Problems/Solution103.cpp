// LeetCode Problem 103: Binary Tree Zigzag Level Order Traversal
#include<iostream>
#include<vector>
#include<algorithm>
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
    // To store the current level nodes
    vector<int> currentLevel; 
    // Flag to determine the order of traversal
    bool leftToRight = true; 
    while (!q.empty()) {
        // Store the queue first element
        TreeNode* currentNode=q.front();
        // Remove the queue first element
        q.pop();
        if(currentNode == nullptr){
            if(!leftToRight){
                // Reverse the current level if right to left
                reverse(currentLevel.begin(),currentLevel.end()); 
            }
            // Add current level to result
            result.push_back(currentLevel); 
            // Clear for next level
            currentLevel.clear(); 
            // Check queue is empty or not
            if(!q.empty()){
                q.push(nullptr);
                leftToRight = !leftToRight; // Toggle the direction for next level
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
    cout<<"Level Order Traversal Zigzag of Binary Tree: "<<endl;
    printLevelOrder(result);
    return 0;
}

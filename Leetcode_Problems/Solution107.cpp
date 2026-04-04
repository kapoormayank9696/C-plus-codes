// LeetCode Problem 107: Binary Tree Level Order Traversal II
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Definition for a binary tree node.
class TreeNode {
    // Public Access Specifier
    public:
    // Data members
    int val;
    TreeNode *left;
    TreeNode *right;
    // Parameterized Constructor
    TreeNode(int x) {
        val=x;
        this->left=nullptr;
        this->right=nullptr;
    }
};
// Function to perform level order traversal in reverse order
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if(root == nullptr) return result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        for(int i=0;i<levelSize;i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.insert(result.begin(), currentLevel); // Insert at the beginning to reverse order
    }
    return result;
}

// Main function
int main() {
    cout<<"Enter the number of nodes in the binary tree: ";
    int n;
    cin >> n;
    if(n <= 0) {
        cout<<"The tree is empty."<<endl;
        return 0;
    }
    vector<TreeNode*> nodes(n);
    cout<<"Enter the values of the nodes (use -1 for null): ";
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        if(val != -1) {
            nodes[i] = new TreeNode(val);
        } else {
            nodes[i] = nullptr;
        }
    }
    // Construct the binary tree
    for(int i=0;i<n;i++) {
        if(nodes[i] != nullptr) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;
            if(leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if(rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }
    vector<vector<int>> result = levelOrderBottom(nodes[0]);
    cout<<"Level Order Traversal in Reverse Order: "<<endl;
    for(const auto& level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}


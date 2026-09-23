// Sum Root to Leaf Numbers Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Class of Binary Tree Node
class Node {
    public:
        int data;
        Node* left;
        Node* right;

    // Parameterized Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    public:
    int index = -1;

        // Insert Function to insert a new node in the binary tree
        Node* insert(int nodes[],int k) {
            index++;
            if(k == 0 || index >= k || nodes[index] == -1) {
                return nullptr;
            }

            Node* newNode = new Node(nodes[index]);
            
            // Recursive Function
            newNode->left = insert(nodes, k - 1); // for left child of Binary Tree(BT)
            newNode->right = insert(nodes, k - 1); // for right child of Binary Tree(BT)
            return newNode;
        }

        // Function to calculate the sum of all root-to-leaf numbers
        int sumNumbers(Node* root) {
            return dfs(root,0);
        }

        // Depth First Search (DFS) Function to calculate the sum of all root-to-leaf numbers
        int dfs(Node* root, int sum) {
            if(root == nullptr) {
                return 0;
            }

            sum = sum * 10 + root->data;

            // If the current node is a leaf node, return the current sum
            if(root->left == nullptr && root->right == nullptr) {
                return sum;
            }

            // Recursively calculate the sum for left and right subtrees
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
};

// Main Function
int main() {
    int nodes[] = {1, 2, 3};
    int val = sizeof(nodes) / sizeof(nodes[0]);
    BinaryTree tree;
    Node* root = tree.insert(nodes, val);

    cout << "Binary Tree Nodes: ";
    for(int i=0; i<val; i++) {
        cout << nodes[i] << "-->";
    }

    cout << "null" << endl;
    int result = tree.sumNumbers(root);
    cout << "Sum of all root-to-leaf numbers: " << result << endl;
    return 0;
}

// LeetCode Problem 559: Maximum Depth of N-ary Tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node class for N-ary Tree
class Node {
    public:
    int val;
    vector<Node *> children;

    // Parameterized Constructor
    Node(int x) {
        this->val = x;
    }
};

// Solution Class
class Solution {
    public:
    // Function to print N-ary Tree preorder
    void printPreOrder(Node *root) {
        if (root == nullptr) {
            return;
        }

        cout << root->val << " ";

        for (Node *child : root->children) {
            printPreOrder(child);
        }
    }

    // Maximum Depth Algorithm
    int maxDepth(Node *root) {
        if (root == nullptr) {
            return 0;
        }

        int depth = 0;

        for (Node* child : root->children) {
            depth = max(depth, maxDepth(child));
        }

        return depth + 1;
    }
};

// Main function
int main() {

    // Create N-ary Tree
    Node *root = new Node(1);

    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));

    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    Solution sol;

    // Print preorder
    cout << "Preorder Traversal: ";
    sol.printPreOrder(root);
    cout << endl;

    // Find maximum depth
    cout << "Maximum Depth of N-ary Tree: "
         << sol.maxDepth(root) << endl;

    return 0;
}

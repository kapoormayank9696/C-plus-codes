// N-ary Tree Level Order Traversal Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// Node class for N-ary Tree
class Node {
    public:
    // Data members
    int val;
    vector<Node *> children;

    // Parameterized Constructor
    Node(int x) {
        val = x;
    }
};

// Function to print N-ary Tree postorder
void printPreOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    for (Node *child : root->children) {
        printPreOrder(child);
    }

    cout << root->val << " ";
}

// Level Order Method
vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;

    if (root == nullptr)
        return result;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> list;
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node *temp = q.front();
            q.pop();

            list.push_back(temp->val);

            for (Node *child : temp->children) {
                q.push(child);
            }
        }
        result.push_back(list);
    }
    return result;
}

// Main function
int main() {

    // Create N-ary Tree
    Node *root = new Node(1);

    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));

    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    // Print preorder
    cout << "Preorder Traversal: ";
    printPreOrder(root);
    cout << endl;

    // Get levelorder list
    vector<vector<int>> result = levelOrder(root);
    cout << "Level Order Traversal: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
// N-ary Tree Postorder Traversal
#include <iostream>
#include <vector>
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

// Preorder Method
vector<int> postorder(Node *root) {
    vector<int> result;

    if (root == nullptr) {
        return result;
    }

    result.push_back(root->val);

    for (Node *child : root->children) {
        vector<int> childResult = postorder(child);

        result.insert(
            result.end(),
            childResult.begin(),
            childResult.end());
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

    // Get postorder list
    vector<int> result = postorder(root);

    cout << "Postorder List: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

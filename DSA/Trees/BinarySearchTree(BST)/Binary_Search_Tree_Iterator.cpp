// Binary Search Tree Iterator Algorithm Implementation In C++
#include <iostream>
#include <stack>
using namespace std;

// Class for Binary Search Tree Node
class BSTNode {
    public:
    // Data Members
    int val;
    BSTNode *left;
    BSTNode *right;

    // Parameterized Constructor
    BSTNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Class for Binary Search Tree Iterator
class BSTIterator {

    public:

    // Stack to store the nodes of the BST
    stack<BSTNode *> st;

    // Default Constructor
    BSTIterator(){}

    // Create BST
    BSTNode *insert(BSTNode *root, int value) {

        // If root is empty
        if (root == nullptr) {
            root = new BSTNode(value);
            return root;
        }

        // Left Subtree
        if (value < root->val) {
            root->left = insert(root->left, value);
        }

        // Right Subtree
        else {
            root->right = insert(root->right, value);
        }

        return root;
    }

    // Print Binary Search Tree
    void printBST(BSTNode *root) {

        if (root == nullptr) {
            cout << "Empty Binary Search Tree.." << endl;
            return;
        }

        printBST(root->left);

        cout << root->val << " ";

        printBST(root->right);
    }

    // Constructor for Iterator
    BSTIterator(BSTNode *root) {
        pushLeft(root);
    }

    // Push leftmost path into stack
    void pushLeft(BSTNode *root) {

        while (root != nullptr){

            st.push(root);

            root = root->left;
        }
    }

    // Return next smallest element
    int next() {

        BSTNode *temp = st.top();

        st.pop();

        if (temp->right != nullptr) {
            pushLeft(temp->right);
        }

        return temp->val;
    }

    // Check whether next element exists
    bool hasNext() {

        return !st.empty();
    }
};

// Main function
int main() {

    int values[] = {9, 3, 20, 15, 7};

    // Object for creating BST
    BSTIterator bst;

    BSTNode *root = nullptr;

    // Create BST
    for (int value : values) {
        root = bst.insert(root, value);
    }

    // Print BST
    cout << "Inorder Traversal of the BST: ";

    bst.printBST(root);

    cout << "\nBinary Search Tree Iterator: ";

    // Create Iterator using root
    BSTIterator iterator(root);

    // Iterate through BST
    while (iterator.hasNext()){

        cout << iterator.next() << " ";
    }

    cout << endl;

    return 0;
}
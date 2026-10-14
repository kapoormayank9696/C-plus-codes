// Populating Next Right Pointers in Each Node
#include <iostream>
using namespace std;

// Solution Class
class Solution116 {
    public:
    // Node class
    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;

        // Parameterized Constructor
        Node(int val) {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
            this->next = nullptr;
        }
    };

    // Index for inserting nodes
    int index = -1;

    // Insert Algorithm
    Node *insert(int nums[], int n) {
        index++;

        if (index >= n || nums[index] == -1) {
            return nullptr;
        }

        Node *newNode = new Node(nums[index]);

        // Recursive Calls
        newNode->left = insert(nums, n);
        newNode->right = insert(nums, n);

        return newNode;
    }

    // Connect Algorithm
    Node *connect(Node *root) {
        if (root == nullptr) {
            return root;
        }

        if (root->left != nullptr) {
            root->left->next = root->right;
        }

        if (root->right != nullptr && root->next != nullptr) {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }

    // Display Binary Tree (Preorder)
    void printTreee(Node *root) {
        if (root == nullptr) {
            return;
        }

        cout << root->val << " ";

        printTreee(root->left);
        printTreee(root->right);
    }

    // Display Next Pointers Level by Level
    void printNextPointers(Node *root) {
        Node *levelStart = root;

        while (levelStart != nullptr) {
            Node *current = levelStart;

            while (current != nullptr) {
                cout << current->val << " -> ";
                current = current->next;
            }

            cout << "NULL" << endl;

            levelStart = levelStart->left;
        }
    }
};

// Main Function
int main() {
    int nums[] = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, 6, -1, -1, 7, -1, -1};

    int n = sizeof(nums) / sizeof(nums[0]);

    Solution116 solution;

    Solution116::Node *root = solution.insert(nums, n);

    cout << "Print the Binary Tree: ";
    solution.printTreee(root);

    Solution116::Node *newRoot = solution.connect(root);

    cout << "\n\nNext Pointers:" << endl;
    solution.printNextPointers(newRoot);

    return 0;
}

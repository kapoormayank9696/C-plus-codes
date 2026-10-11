// LeetCode Problem 1367 : Linked List in Binary Tree
#include <iostream>
using namespace std;

class TreeNode {
    public:
    
    // Data members
    int val;
    TreeNode *left;
    TreeNode *right;

    // Parameterized Constructor
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class ListNode {
    public:
    
    // Data Members
    int val;
    ListNode *next;

    // Parameterized Constructor
    ListNode(int x) {
        val = x;
        this->next = nullptr;
    }
};

// Solution Class
class Solution {
    public:
    int index = -1;

    // Build binary tree from preorder array (-1 = null)
    TreeNode *insert(int arr[], int n) {
        index++;

        if (index >= n || arr[index] == -1) {
            return nullptr;
        }

        TreeNode *node = new TreeNode(arr[index]);
        node->left = insert(arr, n);
        node->right = insert(arr, n);

        return node;
    }

    // Check whether list matches starting at this tree node
    bool checkSubPath(ListNode *head, TreeNode *root) {
        if (head == nullptr) {
            return true;
        }

        if (root == nullptr || head->val != root->val) {
            return false;
        }

        return checkSubPath(head->next, root->left) ||
               checkSubPath(head->next, root->right);
    }

    // Try every tree node as a starting point
    bool isSubPath(ListNode *head, TreeNode *root) {
        if (head == nullptr) {
            return true;
        }

        if (root == nullptr) {
            return false;
        }

        return checkSubPath(head, root) ||
               isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }

    // Print Tree into Pre-Order
    void printPreorder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
};

// Insert a value at the end of linked list
ListNode *insertList(ListNode *head, int val) {
    ListNode *newNode = new ListNode(val);

    if (head == nullptr) {
        return newNode;
    }

    ListNode *temp = head;

    while (temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Print linked list
void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {
        1, 4, 2, -1, 1, 4, 2, -1, 6,
        -1, -1, 8, 1, -1, -1, 3, -1, -1};

    Solution sol;
    TreeNode *root = sol.insert(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "Preorder traversal of the tree: ";
    sol.printPreorder(root);
    cout << endl;

    ListNode *head = nullptr;
    int head_vals[] = {4, 2, 8};

    for (int val : head_vals) {
        head = insertList(head, val);
    }

    cout << "Linked List: ";
    printList(head);

    cout << "Is the linked list a subpath of the binary tree? "
         << (sol.isSubPath(head, root) ? "Yes" : "No") << endl;

    return 0;
}

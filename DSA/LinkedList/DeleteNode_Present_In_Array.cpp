// Delete Nodes From Linked List Present in Array Algorithm Implementation In C++

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Node class
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Solution class
class Solution {
public:
    ListNode* head = nullptr;

    // Insert at end
    void insert(int data) {
        ListNode* newNode = new ListNode(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        ListNode* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Delete nodes whose values are present in nums
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> st;

        // Insert all elements into HashSet
        for (int num : nums) {
            st.insert(num);
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {

            if (st.count(curr->val)) {

                ListNode* nextNode = curr->next;

                prev->next = nextNode;

                delete curr;

                curr = nextNode;
            }
            else {

                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }

    // Display Linked List
    void display() {

        if (head == nullptr) {
            cout << "Linked List is Empty." << endl;
            return;
        }

        ListNode* temp = head;

        while (temp != nullptr) {
            cout << temp->val << " --> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<int> arr = {1, 2, 3, 4, 5};

    // Create Linked List
    for (int x : arr) {
        sol.insert(x);
    }

    cout << "\nOriginal Linked List:";
    sol.display();

    // Modify Linked List
    sol.head = sol.modifiedList(nums, sol.head);

    cout << "After Deleting Nodes:";
    sol.display();

    return 0;
}
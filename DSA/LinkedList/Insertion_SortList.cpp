// Insertion Sort List Algorithm Implementation In C++
#include <iostream>
using namespace std;

// ListNode class
class ListNode {

    // Public Access Modifier
    public:
    // Data Members
    int val;
    ListNode *next;

    // Parameterized Constructor
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// LinkedList Class
class LinkedList {

    // Public Access Modifier
    public:
    ListNode *head = nullptr;

    // Insert
    void insert(int val) {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        ListNode *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insertion Sort List
    ListNode *insertSortList(ListNode *head) {
        if (head == nullptr)
            return head;

        ListNode *helper = new ListNode(0);
        ListNode *current = head;
        ListNode *prev = helper;

        while (current != nullptr) {
            ListNode *next = current->next;
            while (prev->next != nullptr && prev->next->val < current->val) {
                prev = prev->next;
            }
            current->next = prev->next;
            prev->next = current;
            prev = helper;
            current = next;
        }
        return helper->next;
    }

    // Display
    void display(ListNode *head) {
        if (head != nullptr) {
            ListNode *temp = head;
            while (temp != nullptr)
            {
                cout << temp->val << "-->";
                temp = temp->next;
            }
            cout << "null" << endl;
        }
    }
};

// Main function
int main() {
    LinkedList *list;
    list->insert(4);
    list->insert(3);
    list->insert(2);
    list->insert(1);

    cout << "Orignal Linked List: ";
    list->display(list->head);

    list->head = list->insertSortList(list->head);

    cout << "Sorted Linked List: ";
    list->display(list->head);
    return 0;
}

// Design Linked List Algorithms Implementation In C++
#include <iostream>
using namespace std;

class MyLinkedList {
    // Class Of Linked List
    class Node {
        public:
        int val;
        Node* next;

        Node(int v) {
            val = v;
            next = nullptr;
        }
    };

    Node* head;

    public:
    MyLinkedList() {
        head = nullptr;
    }

    // Get the Node Value
    int get(int index) {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            if (count == index)
                return temp->val;

            temp = temp->next;
            count++;
        }
        return -1;
    }

    // Add At Head
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Add At Tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Add At Specific Position
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete At Specific Position
    void deleteAtIndex(int index) {
        if (head == nullptr) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp != nullptr && temp->next != nullptr) {
            if (count == index - 1) {
                Node* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
                return;
            }
            temp = temp->next;
            count++;
        }
    }
};

// Main function
int main() {
    MyLinkedList obj;

    obj.addAtHead(10);
    obj.addAtTail(20);
    obj.addAtHead(5);

    cout << "Print Linked List : ";
    cout << obj.get(0) ; // 5
    cout << obj.get(1) ; // 10
    cout << obj.get(2) << endl; // 20

    obj.addAtIndex(1, 99); // 5 99 10 20

    cout << "After Update Linked List: ";
    cout << obj.get(1) << endl; // 99

    obj.deleteAtIndex(2); // remove 10

    cout << "After delete the Linked List: ";
    cout << obj.get(2) << endl; // 20

    return 0;
}

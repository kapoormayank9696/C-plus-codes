// Design Text Editor Algorithm using Doubly Linked List Implementation In C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Node class of Doubly Linked List
class ListNode {
public:
    char val;
    ListNode* next;
    ListNode* prev;

    ListNode(char val) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Class to implement the Text Editor with cursor movement and text manipulation
class TextEditor {
public:
    ListNode* head;
    ListNode* cursor;

    TextEditor() {
        head = new ListNode('#');
        cursor = head;
    }

    void addText(string text) {
        for (char c : text) {
            ListNode* node = new ListNode(c);

            node->prev = cursor;
            node->next = cursor->next;

            if (cursor->next != nullptr) {
                cursor->next->prev = node;
            }

            cursor->next = node;
            cursor = node;
        }
    }

    int deleteText(int k) {
        int deleted = 0;

        while (cursor != head && deleted < k) {
            ListNode* prev = cursor->prev;

            prev->next = cursor->next;
            if (cursor->next != nullptr) {
                cursor->next->prev = prev;
            }

            ListNode* temp = cursor;
            cursor = prev;
            delete temp;

            deleted++;
        }

        return deleted;
    }

    string cursorLeft(int k) {
        while (cursor != head && k > 0) {
            cursor = cursor->prev;
            k--;
        }

        return getLast10();
    }

    string cursorRight(int k) {
        while (cursor->next != nullptr && k > 0) {
            cursor = cursor->next;
            k--;
        }

        return getLast10();
    }

private:
    string getLast10() {
        string ans = "";

        ListNode* temp = cursor;
        int count = 0;

        while (temp != head && count < 10) {
            ans.push_back(temp->val);
            temp = temp->prev;
            count++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Main function
int main() {
    TextEditor editor;

    editor.addText("Hello");
    cout << editor.cursorLeft(2) << endl; // Output: "He"
    cout << editor.cursorRight(3) << endl; // Output: "Hello"
    cout << editor.deleteText(3) << endl; // Output: 3
    cout << editor.cursorLeft(1) << endl; // Output: "H"
    cout << editor.cursorRight(2) << endl; // Output: "H"

    return 0;
}


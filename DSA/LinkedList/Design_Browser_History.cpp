// Design Browser History Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Node class of Singly Linked List
class ListNode {
    // Public Access Modifier
    public:
    string url;
    ListNode *next;
    ListNode* prev;
    // Parameterized Constructor
    ListNode(string url) {
        this->url = url;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Solution class to implement the browser history operations
class BrowserHistory {
    // Public Access Modifier
    public:
    ListNode* current;
    
    // Constructor
    BrowserHistory(string homepage) {
        current = new ListNode(homepage);
    }

    // Visit Operation
    void visit(string url) {
        ListNode* newNode = new ListNode(url);
        current->next = nullptr; // Clear forward history
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    // Back Operation
    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    // Forward Operation
    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->url;
    }

    // Display History Operation
    void displayHistory() {
        ListNode* temp = current;
        while (temp->prev != nullptr) {
            temp = temp->prev;
        }
        cout << "Browser History: ";
        while (temp != nullptr) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// Main function
int main() {
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");

    cout << "Current URL: " << browserHistory.back(1) << endl; // facebook.com
    cout << "Current URL: " << browserHistory.back(1) << endl; // google.com
    cout << "Current URL: " << browserHistory.forward(1) << endl; // facebook.com
    
    browserHistory.displayHistory();
    browserHistory.visit("linkedin.com");

    cout << "\nCurrent URL: " << browserHistory.forward(2) << endl; // linkedin.com
    cout << "Current URL: " << browserHistory.back(2) << endl; // google.com
    cout << "Current URL: " << browserHistory.back(7) << endl << endl; // leetcode.com
    
    browserHistory.displayHistory();
    return 0;
}


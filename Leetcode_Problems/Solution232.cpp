// Leet Code Problem 232: Implement Queue Using Stack
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1;  // stack for incoming elements
    stack<int> s2;  // stack for outgoing elements

    // Helper to move elements from s1 to s2 if s2 is empty
    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
        // stacks initialize automatically
    }

    // Push element to the back of the queue
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from the front of the queue
    int pop() {
        transfer();              // ensure s2 has elements
        if (s2.empty()) return -1; // queue is empty
        int val = s2.top();
        s2.pop();
        return val;
    }

    // Get the front element
    int peek() {
        transfer();
        if (s2.empty()) return -1;
        return s2.top();
    }

    // Check if queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Test
int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // 10
    cout << "Popped element: " << q.pop() << endl; // 10
    cout << "Front element: " << q.peek() << endl; // 20
    cout << "Is queue empty? "<<(q.empty() ? "Yes" : "No")<<endl; // No
    return 0;
}


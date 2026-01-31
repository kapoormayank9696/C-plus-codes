// Leet Code Problem 225: Implement Stack Using Queue
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
        // Queues initialize automatically
    }

    // Push element onto stack
    void push(int x) {
        q2.push(x);              // Step 1: push to empty queue q2

        // Step 2: move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: swap q1 and q2
        swap(q1, q2);
    }

    // Removes the element on top of the stack
    int pop() {
        if (empty()) return -1;
        int val = q1.front();
        q1.pop();
        return val;
    }

    // Get the top element
    int top() {
        if (empty()) return -1;
        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }
};

// Test
int main() {
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top stack element: " << stack.top() << endl; // 30
    cout << "Popped stack element: " << stack.pop() << endl; // 30
    cout << "Top stack element: " << stack.top() << endl; // 20
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // No

    return 0;
}

// Min Stack Algorithm Implementation In C++
#include <iostream>
#include <stack>
using namespace std;

// Class Minstack
class MinStack {
    // Data Members
    stack<int> st;
    stack<int> minStack;

    // Public Access Specifier
    public:

    // Parameterized Constructor
    MinStack() {}

    // Push Operation
    void push(int value) {
        st.push(value);

        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // Pop Operation
    void pop() {
        if (st.empty()) {
            return;
        }

        int value = st.top();
        st.pop();

        if (value == minStack.top()) {
            minStack.pop();
        }
    }

    // Top Operation
    int top() {
        return st.top();
    }

    // Get Min Value
    int getMin() {
        return minStack.top();
    }

    // Display
    void display() {
        stack<int> temp = st;
        cout << "[";

        while (!temp.empty()) {
            cout << temp.top();
            temp.pop();

            if (!temp.empty()) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }
};

// Main function
int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Display stack (top to bottom): ";
    minStack.display();

    cout << "Minimum Element of the stack: "
         << minStack.getMin() << endl;

    cout << "Top Element into stack: "
         << minStack.top() << endl;

    cout << "Display stack: ";
    minStack.display();

    minStack.pop();

    cout << "After pop:" << endl;
    minStack.display();

    cout << "Top Element: "
         << minStack.top() << endl;

    cout << "Minimum Element: "
         << minStack.getMin() << endl;

    return 0;
}

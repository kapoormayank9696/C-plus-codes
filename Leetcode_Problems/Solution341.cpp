// LeetCode Problem Flatten Nested List Iterator
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// NestedInteger class for local testing
class NestedInteger {
    // Data Members
    bool isInt;
    int value;
    vector<NestedInteger> nestedList;

    public:
    // Constructor for an integer
    NestedInteger(int val) {
        isInt = true;
        value = val;
    }

    // Constructor for a nested list
    NestedInteger(vector<NestedInteger> list) {
        isInt = false;
        nestedList = list;
    }

    // Check It is Integer Or Not
    bool isInteger() {
        return isInt;
    }

    // Get Value
    int getInteger() {
        return value;
    }

    // Get List Into Vector
    vector<NestedInteger> getList() {
        return nestedList;
    }
};

// Class of Neested
class NestedIterator {
    public:
    stack<NestedInteger> st;

    // Parameterized Constructor
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    // Next Operation
    int next() {
        if (hasNext()) {
            NestedInteger current = st.top();
            st.pop();

            return current.getInteger();
        }
        return -1;
    }

    // Has Next Operation
    bool hasNext() {
        while (!st.empty()) {
            NestedInteger current = st.top();

            if (current.isInteger()) {
                return true;
            }

            st.pop();

            vector<NestedInteger> list = current.getList();

            for (int i = list.size() - 1; i >= 0; i--) {
                st.push(list[i]);
            }
        }
        return false;
    }
};

// Main function
int main() {
    vector<NestedInteger> nestedList;

    // Input: [[1,1], 2, [1,1]]
    nestedList.push_back(
        NestedInteger(vector<NestedInteger>{
            NestedInteger(1), NestedInteger(1)}));

    nestedList.push_back(NestedInteger(2));

    nestedList.push_back(NestedInteger(vector<NestedInteger>{
        NestedInteger(1), NestedInteger(1)}));

    NestedIterator iterator(nestedList);

    cout << "Flattened List: ";

    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }

    cout << endl;
    return 0;
}

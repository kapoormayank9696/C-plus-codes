// Check Parentheses are valid or not Algorithm Implementation In C++
#include <iostream>
#include <stack>
using namespace std;
// Function to check if the parentheses are valid
bool isValid(string s) {
    stack<char> st;
    for(char c:s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) {
                return false;
            }
            char top = st.top();
            if((c == ')' && top != '(') || 
            (c == '}' && top != '{') || 
            (c == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

// Main function
int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if(isValid(s)) {
        cout << "The parentheses are valid." << endl;
    } else {
        cout << "The parentheses are not valid." << endl;
    }
    return 0;
}


// Score of Parentheses Algorithm Implementation In C++
#include<iostream>
#include<stack>
using namespace std;

// Solution class
class Solution {
    
    // Public Specifier
    public:
    
    // Function to calculate the score of parentheses
    int scoreOfParentheses(string s) {

        // Create a stack to keep track of the scores
        stack<int> st;
        st.push(0);

        // Iterate through the string and calculate the score based on the rules
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(0);
            } else {
                int innerScore = 0;
                int top = st.top();
                st.pop();
                if(top == 0) {
                    innerScore = 1;
                } else {
                    innerScore = 2*top;
                }
                st.top() += innerScore;
            }
        }
        return st.top();
    }
};

// Main function
int main() {
    Solution solution;
    string s = "()()";
    int score = solution.scoreOfParentheses(s);
    cout << "Score of Parentheses: " << score << endl;
    return 0;
}

// LeetCode Problem 2124 : Check if All A's Appears Before All B's
#include <iostream>
#include <string>
using namespace std;

// Solution Class
class Solution {
public:
    // Function of Check if All A's Appears Before All B's
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};

// Main function
int main() {
    string s = "aaabbb";

    cout << "Print a string: " << s << endl;

    Solution solution;

    if (solution.checkString(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
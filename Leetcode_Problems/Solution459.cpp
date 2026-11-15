// LeetCode Problem 459 : Repeated Substring Pattern 
#include <iostream>
#include <string>
using namespace std;

// Function Of Repeated Substring Pattern
bool repeatedSubstringPattern(string s) {
    string str = s + s;
    return str.substr(1, str.length() - 2).find(s) != string::npos;
}

// Main function
int main() {
    string s = "abab";
    cout << "Display a string: " << s << endl;
    if (repeatedSubstringPattern(s))
    {
        cout << "Repeated Substring Pattern: true" << endl;
    }
    else
    {
        cout << "Repeated Substring Pattern: false" << endl;
    }
    return 0;
}

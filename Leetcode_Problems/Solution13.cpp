// LeetCode Problem 13 : Roman to Integer
#include <iostream>
#include <string>
using namespace std;

// Function to convert roman to integer
int romanToInt(string s) {
    int ans = 0, num = 0, prev = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        switch (s[i]) {
        case 'M':
            num = 1000;
            break;
        case 'D':
            num = 500;
            break;
        case 'C':
            num = 100;
            break;
        case 'L':
            num = 50;
            break;
        case 'X':
            num = 10;
            break;
        case 'V':
            num = 5;
            break;
        case 'I':
            num = 1;
            break;
        }

        if (num < prev) {
            ans -= num;
        }
        else {
            ans += num;
        }

        prev = num;
    }

    return ans;
}

// Main function
int main() {
    string s = "LVIII";
    cout << "Convert a string from Roman to Integer: " << romanToInt(s) << endl;
    return 0;
}

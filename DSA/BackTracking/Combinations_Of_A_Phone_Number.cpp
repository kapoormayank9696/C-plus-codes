// Combinations of a Phone Number Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// class which can solve the combination of a phone numbers
class Solution {
    public:
    
    vector<string> result;

    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    // Function to solve the combination of phone numbers
    void solve(string digits, int index, string temp) {

        if(index == digits.length()) {
            result.push_back(temp);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for(char ch : letters) {
            solve(digits, index + 1, temp + ch);
        }
    }

    // Function to generate combination of phone numbers
    vector<string> letterCombinations(string digits) {

        if(digits.length() == 0) {
            return result;
        }

        solve(digits, 0, "");

        return result;
    }
};

// Main function
int main() {
    string digits;

    cout << "digits = ";
    cin >> digits;
    // Create Object of class solution
    Solution obj;
    // Call the function letter combination
    vector<string> ans = obj.letterCombinations(digits);

    cout << "Output: ";

    for(string str : ans) {
        cout << str << " ";
    }
}


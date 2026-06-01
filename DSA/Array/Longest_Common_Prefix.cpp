// Longest Common Prefix Algorithm Implementation In C++

#include <iostream>
#include <vector>
using namespace std;

// Function to find the longest common prefix among an array of strings
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0]; // Start with the first string as the prefix
    for (size_t i = 1; i < strs.size(); i++) {
        // Compare the current prefix with the next string
        while (strs[i].find(prefix) != 0) { // If the prefix is not at the start of the string
            prefix = prefix.substr(0, prefix.length() - 1); // Remove the last character from the prefix
            if (prefix.empty()) return ""; // If the prefix becomes empty, return an empty string
        }
    }
    return prefix; // Return the longest common prefix
}

// Main function
int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl; // Output: "fl"
    return 0;
}


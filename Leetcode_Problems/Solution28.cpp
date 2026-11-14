// LeetCode Problem 28 : Find the Index of the First Occurrence in a String
#include <iostream>
#include <string>
using namespace std;

// Function To Find Index of the First Occurrence In a String
int strStr(string haystack, string needle) {
    for (int i = 0, j = needle.length(); j <= haystack.length(); i++, j++)
    {
        if (haystack.substr(i, j - i) == needle)
        {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    cout << "Index Of first occurrence in a string: "
         << strStr(haystack, needle) << endl;

    return 0;
}

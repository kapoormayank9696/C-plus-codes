// Reverse a String Algorithm Implementation In C++
#include <iostream>
#include <string>
using namespace std;
// Function to reverse a string
string reverseString(const string& str) {
    string reversedStr = str; // Create a copy of the original string
    int left = 0; // Initialize left pointer
    int right = str.length() - 1; // Initialize right pointer

    // Swap characters until the pointers meet
    while (left < right) {
        swap(reversedStr[left], reversedStr[right]); // Swap characters
        left++; // Move left pointer to the right
        right--; // Move right pointer to the left
    }
    return reversedStr; // Return the reversed string
}

// Main function
int main() {
    string inputStr;
    cout << "Enter a string to reverse: ";
    getline(cin, inputStr); // Read the input string
    string reversedStr = reverseString(inputStr); // Reverse the string
    cout << "Reversed String: " << reversedStr << endl; // Output the reversed string
    return 0;
}


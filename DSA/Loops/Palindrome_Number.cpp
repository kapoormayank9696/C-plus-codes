// Palindrome Number Check Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    // Negative numbers are not palindromes
    if (num < 0) {
        return false;
    }
    int originalNum = num; // Store the original number
    int reversed = 0; // Variable to store the reversed number
    while (num > 0) {
        int digit = num % 10; // Get the last digit
        reversed = reversed * 10 + digit; // Append the digit to the reversed number
        num /= 10; // Remove the last digit
    }
    return originalNum == reversed; // Check if original and reversed numbers are the same
}

// Main function
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }
    return 0;
}


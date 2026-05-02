// Reverse Number Print Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to reverse the digits of a number
void reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10; // Get the last digit
        reversed = reversed * 10 + digit; // Append the digit to the reversed number
        num /= 10; // Remove the last digit
    }
    cout << "Reversed Number: " << reversed << endl;
}

// Main function
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    reverseNumber(number);
    return 0;
}

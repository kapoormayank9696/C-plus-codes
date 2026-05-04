// Binary to Decimal Algorithm Implementation In C++
#include <iostream>
#include <cmath>
using namespace std;
// Function to convert binary number to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, i = 0, remainder;
    while (binary != 0) {
        remainder = binary % 10; // Get the last digit
        decimal += remainder * pow(2, i); // Convert to decimal and add to result
        binary /= 10; // Remove the last digit
        i++; // Increment the position
    }
    return decimal;
}

// Main function
int main() {
    int binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    int decimalNumber = binaryToDecimal(binaryNumber);
    cout << "The decimal equivalent of " << binaryNumber << " is: " << decimalNumber << endl;
    return 0;
}


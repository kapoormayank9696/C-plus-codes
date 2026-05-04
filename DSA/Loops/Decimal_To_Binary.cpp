// Decimal to Binary Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to convert decimal number to binary
void decimalToBinary(int decimal) {
    int binary[32]; // Array to store binary digits
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2; // Get the remainder (binary digit)
        decimal /= 2; // Divide the decimal number by 2
        i++; // Increment the position
    }
    cout << "The binary equivalent is: ";
    for (int j = i - 1; j >= 0; j--) { // Print the binary digits in reverse order
        cout << binary[j];
    }
    cout << endl;
}

// Main function
int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    decimalToBinary(decimalNumber);
    return 0;
}


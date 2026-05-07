// HexaDecimal To Decimal Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Main function
int main() {
    string hex;
    cout << "Input any Hexadecimal number: ";
    cin >> hex;

    // This line converts a hexadecimal string into a decimal integer.
    // stoi means: string to integer
    // Syntax : stoi(string, position, base)
    // E.g stoi("1A", 0, 16);  
    
    int decimal = stoi(hex, 0, 16);

    cout << "The equivalent Decimal Number : " << decimal;

    return 0;
}
// String Length Algorithm Implementation In C++
#include <iostream>
#include <string>
using namespace std;
// Function to calculate the length of a string
int stringLength(const string& str) {
    int length = 0; // Initialize length counter
    for (char ch : str) { // Iterate through each character in the string
        length++; // Increment length for each character
    }
    return length; // Return the calculated length
}

// Main function
int main() {
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr); // Read the input string
    int length = stringLength(inputStr); // Calculate the length of the string
    cout << "Length of the string: " << length << endl; // Output the length
    return 0;
}


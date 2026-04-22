// Nested Loop Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to print a pattern using nested loops
void printPattern(int n) {
    for (int i = 1; i <= n; i++) { // Outer loop for rows
        for(int space = 1; space <= n - i; space++) { // Loop for spaces
            cout << " "; // Print a space
        }
        for (int j = 1; j <= i; j++) { // Inner loop for columns
            cout << j; // Print the column number followed by a space
        }
        cout << endl; // Move to the next line after each row
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the number of rows for the pattern: ";
    cin >> n;
    printPattern(n);
    return 0;
}

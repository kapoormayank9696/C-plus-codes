// Vertical Multiplier Tables Show Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to print the vertical multiplier table
void printVerticalMultiplierTable(int n) {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= n; j++) {
            cout <<j << " x " << i << " = " << i * j << "\t"; // Print the product followed by a tab
        }
        cout << endl; // Move to the next line after each row
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the size of the vertical multiplier table: ";
    cin >> n; // Read the size of the table from user input
    printVerticalMultiplierTable(n); // Call the function to print the table
    return 0;
}

// Table Print Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to print the multiplication table up to n
void printTable(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            cout <<i<<" * "<<j<<" = "<<i * j << "\t"; // Print the product followed by a tab
        }
        cout << endl; // Move to the next line after each row
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the size of the multiplication table: ";
    cin >> n;
    printTable(n);
    return 0;
}


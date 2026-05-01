// Diamond Pattern Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to print the diamond pattern
void printDiamond(int n) {
    // Upper half of the diamond
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower half of the diamond
    for (int i = n - 1; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the number of rows for the diamond pattern: ";
    cin >> n;
    printDiamond(n);
    return 0;
}


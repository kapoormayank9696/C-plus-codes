// Alphabet Pyramid Pattern Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to print the alphabet pyramid pattern
void printAlphabetPyramid(int n) {
     for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "  "; // two spaces for alignment
        }

        // Print increasing letters
        for (char ch = 'A'; ch < 'A' + i; ch++) {
            cout << ch << " ";
        }

        // Print decreasing letters
        for (char ch = 'A' + i - 2; ch >= 'A'; ch--) {
            cout << ch << " ";
        }

        cout << endl;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the number of rows for the alphabet pyramid: ";
    cin >> n;
    printAlphabetPyramid(n);
    return 0;
}


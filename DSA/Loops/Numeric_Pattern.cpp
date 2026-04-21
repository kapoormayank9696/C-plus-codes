// Count Pattern Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to count the occurrences of a pattern in a given string
void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    cout << "Enter the number of rows for the pattern: ";
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}


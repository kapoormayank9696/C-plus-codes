// Print Numbers from 1 to N Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to print numbers from 1 to N
void printNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printNumbers(n);
    return 0;
}

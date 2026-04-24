// Fibonacci Series Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to print the Fibonacci series up to n terms
void fibonacciSeries(int n) {
    int a = 0, b = 1,c;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; i++) {
        cout << a << " "; // Print the current term
        c = a + b; // Calculate the next term
        a = b; // Update a to the next term
        b = c; // Update b to the next term
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    fibonacciSeries(n);
    return 0;
}

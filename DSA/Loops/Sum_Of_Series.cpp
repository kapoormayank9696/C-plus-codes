// Sum of Series Algorithm Implementation In C++
// [1 - X²/2! + X⁴/4! - …]

#include <iostream>
#include <cmath>
using namespace std;
// Function to calculate the sum of the series 1 + 2 + 3 + ... + n
double sumOfSeries(int x, int n) {
    double sum = 1;
    double t = 1;
    for (int i = 1; i <= n; i++) {
        double d = (2 * i) * (2 * i - 1);
        t = -t * x * x / d;
        sum = sum + t;
    }
    return sum; // Return the final sum
}

// Main function
int main() {
    cout<<"Input the Value of x : ";
    int x, n;
    cin >> x; // Read the value of x from user input
    cout << "Enter the value of n: ";
    cin >> n; // Read the value of n from user input
    double result = sumOfSeries(x, n); // Call the function to calculate the sum
    cout << "The sum of the series 1 + 2 + ... + " << n << " is: " << result << endl; // Print the result
    return 0;
}

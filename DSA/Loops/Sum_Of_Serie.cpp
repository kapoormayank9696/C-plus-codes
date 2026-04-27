// Sum of Series Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to calculate the sum of the series 1 + 2 + 3 + ... + n
int sumOfSeries(int n) {
    int sum = 0,t=9;
    for (int i = 1; i <= n; i++) {
        sum = sum + t; // Add the current number to the sum
        t=t*10+9;
    }
    return sum; // Return the final sum
}

// Main function
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n; // Read the value of n from user input
    int result = sumOfSeries(n); // Call the function to calculate the sum
    cout << "The sum of the series 1 + 2 + ... + " << n << " is: " << result << endl; // Print the result
    return 0;
}


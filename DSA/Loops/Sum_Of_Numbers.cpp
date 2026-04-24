// Sum Of Numbers Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to calculate the sum of first N natural numbers
int sumOfNumbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i; // Add each number to the sum
    }
    return sum;
}

// Main function
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = sumOfNumbers(n);
    cout << "The sum of first " << n << " natural numbers is: " << result << endl;
    return 0;
}

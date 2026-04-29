// Perfect Numbers Check Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to check if a number is perfect
bool isPerfect(int num) {
    int sum = 0;
    // Calculate the sum of proper divisors
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; // Add the divisor to the sum
        }
    }
    return sum == num; // A perfect number is equal to the sum of its proper divisors
}

// Main function
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (isPerfect(number)) {
        cout << number << " is a perfect number." << endl;
    } else {
        cout << number << " is not a perfect number." << endl;
    }
    return 0;
}


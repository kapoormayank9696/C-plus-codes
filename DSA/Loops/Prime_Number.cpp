// Prime Number Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false; // Number is divisible by a number other than 1 and itself
        }
    }
    return true; // Number is prime
}

// Main function
int main() {
    int n;
    cout << "Enter a number to check if it is prime: ";
    cin >> n;
    if (isPrime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}


// Check Armstrong Number Algorithm Implementation In C++
#include <iostream>
#include <cmath>
using namespace std;
// Function to calculate the power of a number
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int n = (num == 0) ? 1 : 0;

    while (originalNum != 0) {
        originalNum /= 10;
        n++;
    }
    originalNum = num;
    while (originalNum != 0) {
        int digit = originalNum % 10;
        sum +=power(digit, n);
        originalNum /= 10;
    }

    return sum == num;
}

// Main function
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num))
        cout << num << " is an Armstrong number." << endl;
    else
        cout << num << " is not an Armstrong number." << endl;

    return 0;
}


// Perfect Numbers in a Range Algorithm Implementation In C++
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
    int start, end;
    cout << "Input the starting range or number: ";
    cin >> start;
    cout << "Input the ending range or number: ";
    cin >> end;
    cout << "Perfect numbers in the range [" << start << ", " << end << "] are: ";
    for (int i = start; i <= end; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}

// LeetCode Problem 4078 : Three Fibonacci Sum
#include <iostream>
using namespace std;

// Function to find the sum of 3 fibonnaci series
bool threeFibonacciSum(int n) {
    int a = 0, b = 1, c = 1;
    while (a + b + c <= n)
    {
        if (a + b + c == n)
        {
            return true;
        }
        int k = b + c;
        b = a;
        a = k;
        c = k;
    }
    return false;
}

// Main function
int main() {
    int n = 16;
    cout << "Check this is fibonaaci series or not: " << boolalpha << threeFibonacciSum(n) << endl;
    return 0;
}

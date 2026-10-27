// LeetCode Problem 4092 : Binary Digit Score
#include<iostream>
using namespace std;

// Function of Calculate Score 
int calculateScore(int a, int b) {
    int s1 = 0;
    int s2 = 0;
    while (a > 0) {
        int r = a % 2;
        if (r == 1) {
            s1++;
        }
        a = a / 2;
    }

    while (b > 0) {
        int r = b % 2;
        if (r == 1) {
            s2++;
        }
        b = b / 2;
    }

    if (s1 >= s2) {
        return s1 * s2;
    }
    return s1 == 0 ? 0 : s2 / s1;
}

// Main function
int main() {
    int a = 14, b = 6;
    cout << "A is: " << a << endl;
    cout << "B is: " << b << endl;
    cout << "Binary Digit Score : " << calculateScore(a,b) << endl;
    return 0;
}

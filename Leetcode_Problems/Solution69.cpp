// LeetCode Problem 69: Sqrt(x)

#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the integer square root of a number
int mySqrt(int x) {
    return (int)sqrt(x);
}

// Main function
int main() {
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    cout<<"Square root of "<<x<<" is "<<mySqrt(x)<<endl;
    return 0;
}


// Missing Number in an array Algorithm Implementation In C++
#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number in an array
int missingNumber(int nums[], int n) {
    int xorValue = n; // Initialize xorValue with n
    for (int i = 0; i < n; i++) {
        xorValue = xorValue ^ i ^ nums[i];
    }
    return xorValue;
}

// Main function
int main() {
    int nums[] = {3, 0, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Missing number is: " << missingNumber(nums, n) << endl;
    return 0;
}

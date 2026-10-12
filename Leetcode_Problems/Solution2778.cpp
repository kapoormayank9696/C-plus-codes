// LeetCode Problem 2778 : Sum of Squares of Special Elements
#include <iostream>
using namespace std;

// Function Of Sum Of Squares
int sumOfSquares(int nums[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (n % (i + 1) == 0) {
            sum = sum + (nums[i] * nums[i]);
        }
    }
    return sum;
}

// Main function
int main() {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Print Original Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\nSum Of Squares from An Array: " << sumOfSquares(nums, n);
    return 0;
}

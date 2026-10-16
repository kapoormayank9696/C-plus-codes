// LeetCode Problem 198 : House Robber
#include <iostream>
#include <algorithm>
using namespace std;

// Function To Perform The House Robber
int rob(int nums[], int n) {
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int current = max(prev1, num + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

// Main function
int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Print an array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "House robbery Maximum : " << rob(nums, n) << endl;
    return 0;
}

// LeetCode Problem 169: Majority Element
#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the majority element in an array
int majorityElement(int nums[], int n) {
    sort(nums, nums + n);
    return nums[n / 2];
}

// Main function
int main() {
    int nums[] = {3, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << "The majority element is: " << majorityElement(nums, n) << endl;
    return 0;
}

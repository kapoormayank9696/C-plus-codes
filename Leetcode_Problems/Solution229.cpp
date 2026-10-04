// LeetCode Problem 229: Majority Element II
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the majority elements in an array that appear more than n/3 times
vector<int> majorityElement(int nums[], int n) {

    // Sort array
    sort(nums, nums + n);

    // Dynamic array to store the answer
    vector<int> ans;

    int count = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
        }
        else {
            if (count > n / 3) {
                ans.push_back(nums[i - 1]);
            }
            count = 1;
        }
    }

    if (count > n / 3) {
        ans.push_back(nums[n - 1]);
    }

    return ans;
}

// Main function
int main() {
    int nums[] = {3, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    vector<int> result = majorityElement(nums, n);

    cout << "Majority elements(appearing more than n/3 times): ";
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}

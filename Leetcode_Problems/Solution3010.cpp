// LeetCode Problem 3010: Divide an Array Into Subarrays With Minimum Cost I
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Method to count the minimum cost of subarrays
long minimumCost(const vector<int>& nums) {
    int n = nums.size();
    int leftMin = nums[1];
    int ans = INT_MAX;

    // Scan for the 2nd and 3rd subarray splits
    for (int j = 2; j < n; j++) {
        ans = min(ans, nums[0] + leftMin + nums[j]);
        leftMin = min(leftMin, nums[j]);
    }
    return ans;
}

// Main function
int main() {
    vector<int> nums = {1, 2, 3, 12};
    cout << "Minimum cost: " << minimumCost(nums) << endl;
    return 0;
}

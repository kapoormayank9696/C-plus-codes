// LeetCode Problem 462: Minimum Moves to Equal Array Elements II
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the minimum moves to equal array elements
int minMoves2(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());
    int median = nums[n / 2];
    int moves = 0;

    for (int num : nums) {
        moves += abs(num - median);
    }

    return moves;
}

// Main function
int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Input array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    int result = minMoves2(nums);
    cout << "Minimum moves to equal array elements: " << result << endl;
    return 0;
}

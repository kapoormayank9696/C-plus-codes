// LeetCode Problem 3736 : Minimum Moves to Equal Array Elements III
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the minimum moves to equal array elements
int minMoves(vector<int>& nums) {
    int max = INT_MIN;
    int sum = 0;
    int n = nums.size();

    for (int num : nums) {
        max = std::max(num, max);
        sum += num;
    }

    return n * max - sum;
}

// Main function
int main() {
    vector<int> nums = {1, 2, 3};

    cout << "Minimum moves: " << minMoves(nums) << endl;

    return 0;
}

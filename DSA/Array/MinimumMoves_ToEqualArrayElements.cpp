// Minimum Moves to Equal Array Elements Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the minimum moves to equal array elements
int minMoves(vector<int>& nums) {
    int minElement = *min_element(nums.begin(), nums.end());
    int moves = 0;
    for (int num : nums) {
        moves += num - minElement;
    }
    return moves;
}

// Main function
int main() {
    vector<int> nums = {1, 2, 3};
    int result = minMoves(nums);
    cout << "Minimum moves to equal array elements: " << result << endl;
    return 0;
}

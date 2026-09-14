// LeetCode Problem 136: Single Number
#include<iostream>
#include<vector>
using namespace std;

// Main function
int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = 0;

    for (int num : nums) {
        result = result ^ num; // XOR operation
    }

    cout << "The single number is: " << result << endl;
    return 0;
}

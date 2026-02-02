// LeetCode Problem 961: N-Repeated Element in Size 2N Array
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to find N-repeated element
int repeatedNTimes(const vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) {
            return num;
        }
        seen.insert(num);
    }
    return -1; // This should never happen
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = repeatedNTimes(nums);
    cout << "Repeated element: " << result << endl;
    return 0;
}


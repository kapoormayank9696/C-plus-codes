// LeetCode Problem 2089 Find Target Indices After Sorting Array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function To Find Target Indices After Sorting Array
vector<int> targetIndices(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> arr;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (target == nums[i]) {
            arr.push_back(i);
        }
    }
    return arr;
}

// Main function
int main() {
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    cout << "Print Orignal Array : ";
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0) cout << ",";
        cout << nums[i];
    }
    cout << "]" << endl;

    vector<int> result = targetIndices(nums, target);
    cout << "Sorted Array: ";
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0) cout << ",";
        cout << nums[i];
    }
    cout << "]" << endl;

    cout << "Target Indices Array: ";
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << ",";
        cout << result[i];
    }
    cout << "]" << endl;
    return 0;
}

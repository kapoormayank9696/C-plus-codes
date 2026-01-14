// Leetcode Problem 192: Merge Sort

#include <iostream>
#include <vector>
using namespace std;

// Function to print vector
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\n";
}

// Merge two sorted vectors
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i++]);
        } else {
            merged.push_back(right[j++]);
        }
    }
    while (i < left.size()) merged.push_back(left[i++]);
    while (j < right.size()) merged.push_back(right[j++]);
    return merged;
}

// Merge Sort function
vector<int> Mergesort(const vector<int>& nums) {
    if (nums.size() <= 1) return nums;

    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid, nums.end());

    return merge(Mergesort(left), Mergesort(right));
}

// Main function
int main() {
    cout << "Enter number of terms: ";
    int n;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Original Array: ";
    printArray(nums);

    vector<int> sorted = Mergesort(nums);
    cout << "After Sorting: ";
    printArray(sorted);

    return 0;
}


// Minimum Common Value Algorithm Implementation In C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Class to find the minimum common value between two sorted arrays
class Solution {
    public:
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2= nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                return nums1[i]; // Return the common value
            } if (nums1[i] < nums2[j]) {
                i++; // Move pointer in nums1
            } else {
                j++; // Move pointer in nums2
            }
        }
        return -1; // No common value found
    }
};

// Main function
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 3, 5, 6, 7};
    int result = sol.getCommon(nums1, nums2);
    cout << "Minimum Common Value: " << result << endl;
    return 0;
}


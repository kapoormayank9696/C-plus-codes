#include<iostream>
#include<vector>
using namespace std;

// Solution Class
class Solution {
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                max = max(count, max);
                count = 0;
                continue;
            }
            count++;
        }
        max = max(count, max);
        return max;
    }
};

// Main function
int main() {
    Solution solution;
    vector<int> nums = {1,1,0,1,1,1,0,1,1};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
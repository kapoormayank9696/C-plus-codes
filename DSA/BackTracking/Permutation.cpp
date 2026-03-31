// Permutation Generation using Backtracking Algorithm Implementation in C++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    // Function to generate permutations using backtracking
    void permute(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) continue; // Skip used elements
            used[i] = true; // Mark element as used
            temp.push_back(nums[i]); // Include element
            permute(nums, result, temp, used); // Recursive call
            temp.pop_back(); // Backtrack (remove last element)
            used[i] = false; // Mark element as unused
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        permute(nums, result, temp, used);
        return result;
    }
};

// Main function
int main() {
    Solution obj;
    cout<<"Enter number of elements: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = obj.permute(nums);
    cout << "Permutations are:\n";
    for(auto permutation : result) {
        cout << "[ ";
        for(int i = 0; i < permutation.size(); i++) {
            cout << permutation[i];
            // Add a comma except for the last element
            if (i < permutation.size() - 1) cout << ", "; 
        }
        cout << "]\n";
    }
    return 0;
}

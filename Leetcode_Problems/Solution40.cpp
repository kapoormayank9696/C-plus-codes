// Leetcode 40: Combination Sum II
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Function to generate combinations using backtracking
void combine(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int index,int target){
    if(target == 0) {
        result.push_back(temp);
        return;
    }
    if(target < 0) return;
    for(int i = index; i < nums.size(); i++) {
        if(i > index && nums[i] == nums[i-1]) continue; // Skip duplicates
        if(nums[i] > target) break;
        temp.push_back(nums[i]); // Include element
        combine(nums, result, temp, i + 1, target - nums[i]); // Recursive call
        temp.pop_back(); // Backtrack (remove last element)
    }
}


// Main function
int main() {
    cout<<"Enter number of elements: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter target: ";
    int target;
    cin >> target;
    // Sort the input to handle duplicates
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> result;
    vector<int> temp;
    combine(nums, result, temp, 0, target);
    cout << "Combinations are:\n";
    for(auto combination : result) {
        cout << "[ ";
        for(int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            // Add a comma except for the last element
            if (i < combination.size() - 1) cout << ", "; 
        }
        cout << "]\n";
    }
    return 0;
}


// LeetCode Problem 39: Combination Sum
#include<iostream>
#include<vector>
using namespace std;
// Function to generate combinations using backtracking
void combine(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int index,int target){
    if(target == 0) {
        result.push_back(temp);
        return;
    }
    if(target < 0) return;
    for(int i = index; i < nums.size(); i++) {
        temp.push_back(nums[i]); // Include element
        combine(nums, result, temp, i, target - nums[i]); // Recursive call (i instead of i + 1 for unlimited usage)
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

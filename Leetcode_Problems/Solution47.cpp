// LeetCode Problem 47: Permutations II
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Function to find all unique permutations
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector
<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
            continue;
        }
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

// Main function
int main() {
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements : ";
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(n, false);
    backtrack(nums, used, current, result);
    
    cout<<"Unique Permutations are : "<<endl;
    for (const auto& perm : result) {
        cout<<"[ ";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i != perm.size() - 1) {
                cout << ", ";
            }
        }
        cout<<"]"<<endl;
    }
    
    return 0;
}

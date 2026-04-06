// Combination Sum III Algorithm Implementation In C++
#include <iostream>
#include <vector>
using namespace std;

// Solution class to find combinations of k numbers that add up to n
class Solution {
public:
    void backtrack(int k, int target, vector<vector<int>>& result,
                   vector<int>& combination, int start) {
        if (combination.size() == k) {
            if (target == 0) {
                result.push_back(combination);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > target) break;

            combination.push_back(i);
            backtrack(k, target - i, result, combination, i + 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(k, n, result, combination, 1);
        return result;
    }
};

// Main function
int main() {
    int k, n;
    cout << "Enter number of elements (k): ";
    cin >> k;
    cout << "Enter target sum (n): ";
    cin >> n;
    Solution obj;
    vector<vector<int>> result = obj.combinationSum3(k, n);
    cout << "\nCombinations are:\n";
    if (result.empty()) {
        cout << "No valid combinations found." << endl;
        return 0;
    }
    for (auto& comb : result) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}

// Leetcode Problem 77: Combinations
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Function to generate combinations using backtracking
void combine(vector<vector<int>>& result, vector<int>& temp, int start,int n,int k){
    if(temp.size() == k) {
        result.push_back(temp);
        return;
    }
    for(int i = start; i <= n; i++) {
        temp.push_back(i); // Include element
        combine(result, temp, i + 1, n, k); // Recursive call
        temp.pop_back(); // Backtrack (remove last element)
    }
}

// Main function
int main() {
    cout<<"Enter a number: ";
    int n;
    cin >> n;
    cout << "Enter number of times: ";
    int k;
    cin >> k;
    vector<vector<int>> result;
    vector<int> temp;
    combine(result, temp, 1,n,k);
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



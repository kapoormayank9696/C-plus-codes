// Prefix Common Array of Two Arrays Algorithm Implementation In C++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Class to solve the problem
class Solution {
    public:
    // function to find the prefix common array of two arrays
    vector<int> findThePrefixCommonArray(vector<int>& A,vector<int>& B) {
        int n=min(A.size(),B.size());
        vector<int> freq(n+1,0);
        vector<int> ans(n,0);
        int count = 0;
        for(int i=0;i<n;i++) {

            freq[A[i]]++;
            if(freq[A[i]] == 2) {
                count++;
            }

            freq[B[i]]++;
            if(freq[B[i]] == 2) {
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};

// Main function
int main() {
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    Solution sol;
    vector<int> result = sol.findThePrefixCommonArray(A, B);
    cout<<"Prefix Common Array: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}


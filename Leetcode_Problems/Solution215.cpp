// LeetCode Problem 215: Kth Largest Element in an Array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Main function
int main() {
    int n,k;
    cout<<"Enter number of terms: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    cout<<"Enter k: ";
    cin>>k;
    // Sort in descending order
    sort(nums.begin(), nums.end(), greater<int>());
    cout << "Sorted Array (descending): ";
    for(int i=0;i<n;i++) {
        cout<<nums[i]<<" ";
    }
    cout <<"\n"<< k << "th largest element is: " << nums[k-1] << endl;
    return 0;
}

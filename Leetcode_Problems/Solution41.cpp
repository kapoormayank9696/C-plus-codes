// LeetCode Problem 41: First Missing Positive
#include<iostream>
#include<vector>
using namespace std;

// Function to find the positive missing number from an array
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    // Step 1: Place elements at correct positions
    for(int i = 0; i < n; i++) {
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    // Step 2: Find first missing positive
    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }
    // Step 3: If all positions correct
    return n + 1;
}

// Function to print an array
void printArray(vector<int>& arr) {
    for(int num:arr) {
        cout<<num<<" ";
    }
    cout<<endl;
}

// Main function
int main() {
    int n;
    cout<<"Enter size of an array: ";
    cin>>n;
    cout<<"Enter elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Display an array: ";
    printArray(arr);
    cout << "First missing positive: "<< firstMissingPositive(arr);
    return 0;
}

// LeetCode Problem 1365: How Many Numbers Are Smaller Than the Current Number
#include<iostream>
#include<vector>
using namespace std;
// Function to count how many numbers are smaller than the current number
vector<int> smallerNumberThanCurrent(vector<int>& nums) {
    // Find the maximum and minimum values in the array to determine the range
    int max=nums[0];
    int min=nums[0];
    // Find the maximum and minimum values in the array
    for(int num:nums) {
        if(num > max) max=num;
        if(num < min) min=num;
    }
    // Create a count array to store the frequency of each number
    vector<int> count(max-min+1, 0);
    for(int num:nums) {
        count[num-min]++;
    }
    // Calculate the cumulative count
    for(int i=1;i<count.size();i++) {
        count[i]+=count[i-1];
    }
    for(int i=0;i<nums.size();i++) {
        if(nums[i] == min) {
            nums[i]=0;
        }else{
            nums[i]=count[nums[i]-min-1];
        }
    }
    return nums;
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    cout<<"Enter the number of elements: ";
    int n;
    cin >> n;
    cout<<"Enter the elements: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout<<"Original Array: ";
    printArray(nums);
    vector<int> result = smallerNumberThanCurrent(nums);
    cout<<"Result Array: ";
    printArray(result);
}

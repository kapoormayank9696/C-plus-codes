// LeetCode Problem 189: Rotate Array
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// Function to reverse the element of an array
void reverse(vector<int>& nums,int start,int end) {
    while(start < end) {
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
}

// Rotate array by k positions to the right
void rotateArray(vector<int>& arr,int n,int k) {
    k=k%n;
    // Step 1: reverse whole array
    reverse(arr,0,k-1);
    // Step 2: reverse first k elements
    reverse(arr,k,n-1);
    // Step 3: reverse remaining n-k elements
    reverse(arr,0,n-1);
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
    int n,k;
    cout<<"Enter size of an arrays: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"1-d Array: ";
    printArray(arr);
    cout<<"Enter value of k: ";
    cin>>k;
    rotateArray(arr,n,k);
    cout << "After Right Rotation by " << k << ": ";
    printArray(arr);
    return 0;
}


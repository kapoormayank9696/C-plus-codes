// Move Zeroes Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;
// Function to moves the zeroes at end point
void moveZeroes(vector<int>& arr,int n) {
    int j = 0; // position for next non-zero element
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Function to print an array
void printArray(vector<int>& arr,int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Main function
int main() {
    int n,values;
    cout<<"Enter number of terms: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Original Array: ";
    printArray(arr,n);
    moveZeroes(arr,n);
    cout<<"After moving zeroes at end: ";
    printArray(arr,n);
    return 0;
}

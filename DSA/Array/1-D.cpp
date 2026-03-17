// 1-D Array Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Function to print the 1-d array
void printArray(const vector<int>& nums) {
    for(int num:nums) {
        cout<<num<<" ";
    }
    cout<<endl;
}

// Main Function
int main() {
    cout<<"Enter matrix size: ";
    int n;
    cin>>n;
    // Define the vector means dynamic array
    vector<int> arr(n);
    cout<<"Enter matrix elements row by row: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print Original 1-d Array: ";
    printArray(arr);
    return 0;
}


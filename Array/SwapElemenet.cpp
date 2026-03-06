// Swap the elements Implementation In C++
#include<iostream>
#include<vector>
using namespace std;


// Function to print the array
void printArray(vector<int>& arr) {
    for(int num:arr) {
        cout<<num<<" ";
    }
    cout<<endl;
}


// Function to swapping from 1-d array of all elements
void swappOfArray(vector<int>& arr,int n) {
    for(int i=0;i<n/2;i++) {
        swap(arr[i], arr[n-i-1]);
    }
}


// Main function
int main() {
    int n;
    cout<<"Enter size of matrix: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print the 1-d array: ";
    printArray(arr);
    swappOfArray(arr,n);
    cout<<"After swapping all elements from 1-d: ";
    printArray(arr);
    return 0;
}


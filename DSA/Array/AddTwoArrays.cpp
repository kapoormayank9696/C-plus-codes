// Add Two Arrays In First Array Implementation In C++
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

// Function to add both arrays in first array
void addArrays(vector<int>& arr,int n,vector<int>& arr1,int m) {
    for(int i = 0; i < m; i++) {
        arr.push_back(arr1[i]);
    }
}

// Main function
int main() {
    int n,m;
    cout<<"Enter size of first array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print the first array: ";
    printArray(arr);
    cout<<"\nEnter size of second array: ";
    cin>>m;
    vector<int> arr1(m);
    for(int i=0;i<m;i++) {
        cin>>arr1[i];
    }
    cout<<"Print the second array: ";
    printArray(arr1);
    addArrays(arr,n,arr1,m);
    cout<<"After adding both arrays all elements: ";
    printArray(arr);
    return 0;
}


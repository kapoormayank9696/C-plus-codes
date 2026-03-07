// Insert The Element At End Position Of Array Implementation In C++
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

// Function to insert the end position of array
void insertAtEnd(vector<int>& arr,int m) {
    arr.push_back(m);
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
    cout<<"Enter element for insert at end: ";
    cin>>m;
    insertAtEnd(arr,n,m);
    cout<<"Insert element in array at beignning: ";
    printArray(arr);
    return 0;
}


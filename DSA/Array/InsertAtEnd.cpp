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

// Function to insert at end position of array
void insertAtEnd(vector<int>& arr,int m) {
    arr.push_back(m);
}

// Main function
int main() {
    int n,m;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print the array: ";
    printArray(arr);
    cout<<"Enter element for insert at end: ";
    cin>>m;
    insertAtEnd(arr,m);
    cout<<"Insert element at end of an array: ";
    printArray(arr);
    return 0;
}


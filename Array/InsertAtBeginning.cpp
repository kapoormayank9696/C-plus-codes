// Insert The Element At Beginning Position Of Array Implementation In C++
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

// Function to insert at beginning position of array
void insertAtBeginning(vector<int>& arr,int m) {
    arr.insert(arr.begin(),m);
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
    cout<<"Enter element for insert at beginning: ";
    cin>>m;
    insertAtBeginning(arr,m);
    cout<<"Insert element at beignning of an array: ";
    printArray(arr);
    return 0;
}


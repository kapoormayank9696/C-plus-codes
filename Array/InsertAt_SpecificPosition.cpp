// Insert The Element At Specific Position Of Array Implementation In C++
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

// Function to insert at specific position of array
void insertAtSpecific(vector<int>& arr,int index,int m) {
    // Check the index is valid or not valid
    if(index < 0 || index > arr.size()) {
        cout<<"Invalid index"<<endl;
        return;
    }
    arr.push_back(0);  // increase size
    // Shift the elements of an array
    for(int i=arr.size()-1;i > index;i--) {
        arr[i]=arr[i-1];
    }
    // Store the new element at specific position
    arr[index]=m;
}

// Main function
int main() {
    int n,m,index;
    cout<<"Enter size of first array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print the array: ";
    printArray(arr);
    cout<<"Enter index: ";
    cin>>index;
    cout<<"Enter element for insert at specific position: ";
    cin>>m;
    insertAtSpecific(arr,index,m);
    cout<<"Insert element at specific position of an array: ";
    printArray(arr);
    return 0;
}


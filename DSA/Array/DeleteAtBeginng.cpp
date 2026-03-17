// Delete The Element At Beginning Position Of Array Implementation In C++
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

// Function to delete at beginning position of array
void deleteAtBeginning(vector<int>& arr,int n) {
    if(arr.empty()) {
        cout<<"Array is an empty..."<<endl;
        return;
    }
    for(int i=0;i<n-1;i++) {
        arr[i]=arr[i+1];
    }
    arr.pop_back(); // Reduce size
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
    deleteAtBeginning(arr,n);
    cout<<"Delete element at beignning of an array: ";
    printArray(arr);
    return 0;
}


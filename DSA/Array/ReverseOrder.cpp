// Reverse Order Print 1-d Array
#include<iostream>
#include<vector>
using namespace std;

// Function to display the 1-d array
void printArray(vector<int>& arr) {
    for(int num:arr) {
        cout<<num<<" ";
    }
    cout<<endl;
}

// Function to display the 1-d array in reverse order
void reverseOrder(vector<int>& arr,int n) {
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Main function
int main() {
    cout<<"Enter size of 1-d matrix: ";
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Original 1-d Array: ";
    printArray(arr);
    cout<<"Reverse order 1-d Array: ";
    reverseOrder(arr,n);
    return 0;
}


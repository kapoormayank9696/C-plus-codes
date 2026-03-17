// Delete The Element At Specific Position Of Array Implementation In C++
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

// Function to delete at specific position of array
void deleteAtSpecific(vector<int>& arr,int index) {
    if(arr.empty()) {
        cout<<"Array is an empty..."<<endl;
        return;
    }
    if(index < 0 || index >= arr.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    for(int i=index;i<arr.size()-1;i++) {
        arr[i]=arr[i+1];
    }
    arr.pop_back(); // Reduce size
}

// Main function
int main() {
    int n,m,index;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print the array: ";
    printArray(arr);
    cout<<"Enter position where element is delete: ";
    cin>>index;
    deleteAtSpecific(arr,index);
    cout<<"Delete element at specific position of an array: ";
    printArray(arr);
    return 0;
}


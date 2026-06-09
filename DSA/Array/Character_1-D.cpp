// Character 1-D Array Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Function to print the 1-d array
void printArray(const vector<char>& chars) {
    for(char ch:chars) {
        cout<<ch<<" ";
    }
    cout<<endl;
}

// Main Function
int main() {

    cout<<"Enter array size: ";
    int n;
    cin>>n;

    // Define the vector means dynamic array
    vector<char> arr(n);
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<"Print Original 1-d Character Array: ";
    printArray(arr);
    return 0;
}

// Minimum Value find Algorithms Implementation In C++
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// Function to find the minimum element from an array
int minElement(vector<int>& arr) {
    int small=arr[0];
    for(int num:arr) {
        if(small > num) {
            small=num;
        }
    }
    return small;
}

// Function to print an array
void printArray(vector<int>& arr) {
    for(int num:arr) {
        cout<<num<<" ";
    }
    cout<<endl;
}

// Main function
int main() {
    int n;
    cout<<"Enter size of an array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"1-d Array: ";
    printArray(arr);
    cout<<"Minimum element from an array: "<<minElement(arr)<<endl;
    return 0;
}


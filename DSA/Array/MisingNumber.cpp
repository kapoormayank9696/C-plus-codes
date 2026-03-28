// Mising Number Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;
// Function to find the missing number from an aray
int findMissing(vector<int>& arr,int n) {
    int expected=n*(n+1)/2;
    int actual=0;
    for(int num:arr) {
        actual=actual+num;
    }
    return expected-actual;
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
    cout<<"Enter elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Display an array: ";
    printArray(arr);
    cout<<"Mising number from an array: "<<findMissing(arr,n)<<endl;
    return 0;
}


// LeetCode Problem 442: Find All Duplicates in an Array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Function to store the dupliate elements into new vector
vector<int> findDuplicates(vector<int>& arr) {
    vector<int> list;
    // sort the array
    sort(arr.begin(), arr.end());
    for(int i=1;i<arr.size();i++) {
        if(arr[i] == arr[i-1]) {
            list.push_back(arr[i]);
        }
    }
    return list;
}

// Function to display a vector
void display(vector<int>& arr) {
    for(int num:arr) {
        cout<<num<<" ";
    }
    cout<<endl;
}

// Main function
int main() {
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Display the array: ";
    display(arr);
    arr=findDuplicates(arr);
    cout<<"Display the duplicate elements from an array: ";
    display(arr);
    return 0;
}


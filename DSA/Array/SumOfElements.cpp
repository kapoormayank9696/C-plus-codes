// Sum of arrays element Implementation In C++
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

// Function to return the sum of 1-d array all elements
int sumOfArray(vector<int>& arr) {
    int sum=0;
    for(int num:arr) {
        sum=sum+num;
    }
    return sum;
}

// Main function
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print the 1-d array: ";
    printArray(arr);
    cout<<"Sum of all elements of 1-d: "<<sumOfArray(arr);
    return 0;
}


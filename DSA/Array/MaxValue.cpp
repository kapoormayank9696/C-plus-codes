// Maximum Value find Algorithms Implementation In C++
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// Function to find the maximum element from an array
int maxElement(vector<int>& arr) {
    int big=arr[0];
    for(int num:arr) {
        if(big < num) {
            big=num;
        }
    }
    return big;
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
    cout<<"Enter size of matrix: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"1-d Array: ";
    printArray(arr);
    cout<<"Maximum element from an array: "<<maxElement(arr)<<endl;
    return 0;
}


// 2-D Array Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Function to print the 1-d array
void printArray(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for(int num:row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

// Main Function
int main() {
    cout<<"Enter matrix size(m,n): ";
    int n,m;
    cin>>n>>m;
    // Define the vector means dynamic array
    vector<vector<int>> arr(n,vector<int>(m));
    cout<<"Enter matrix elements row by row: ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"Print Original 2-d Array: "<<endl;
    printArray(arr);
    return 0;
}


// Lower Triangle Changes Into Zero Implementation In C++
#include<iostream>
#include<vector>
using namespace std;
// Function to display the 2-d array
void display(vector<vector<int>>& arr,int n,int m){
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// Function to print in reverse order
void reverseOrder(vector<vector<int>>& arr,int n,int m) {
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// Main function
int main() {
    int n,m;
    // User input
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    // Define the vector for dynamic array
    vector<vector<int>> arr(n,vector<int>(m));
    cout<<"Enter Elements:\n";
    // User give the values which store the values in an array
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"Print original 2-d array:\n";
    display(arr,n,m);
    cout<<"Print reverse order: \n";
    reverseOrder(arr,n,m);
    return 0;
}


// Sprial Matrix Traversal Order Implementation In C++
// Spiral Matrix(Clock wise direction)

#include<iostream>
#include<vector>
using namespace std;

// Function to display the array
void display(vector<vector<int>>& arr,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// Correct Spiral Traversal
void spiralMatrix(vector<vector<int>>& arr) {
    int top = 0;
    int bottom = arr.size() - 1;
    int left = 0;
    int right = arr[0].size() - 1;

    while(top <= bottom && left <= right) {

        // Left to Right
        for(int i = left; i <= right; i++)
            cout << arr[top][i] << " ";
        top++;
        // Top to Bottom
        for(int i = top; i <= bottom; i++)
            cout << arr[i][right] << " ";
        right--;
        // Right to Left
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                cout << arr[bottom][i] << " ";
            bottom--;
        }
        // Bottom to Top
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                cout << arr[i][left] << " ";
            left++;
        }
    }
}

// Main function
int main() {
    int n,m;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"Print an array: "<<endl;
    display(arr,n,m);
    cout<<"Spiral Matrix Order Traversal: "<<endl;
    spiralMatrix(arr);
    return 0;
}

// Second Largest Value find Algorithms Implementation In C++
#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
using namespace std;
// Function to find the maximum element from an array
int second_maxElement(vector<int>& arr) {
    if(arr.size() < 2) return -1; // edge case
    int first = INT_MIN, second = INT_MIN;
    for(int num : arr) {
        if(num > first) {
            second = first;
            first = num;
        }
        else if(num > second && num != first) {
            second = num;
        }
    }
    if(second == INT_MIN) return -1; // no second largest
    return second;
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
    cout<<"Enter size of an arrays: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"1-d Array: ";
    printArray(arr);
    cout<<"Second Largest element from an array: "<<second_maxElement(arr)<<endl;
    return 0;
}


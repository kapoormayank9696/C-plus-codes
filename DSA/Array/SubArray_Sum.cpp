// Maximum Sub Arrays(Kadane’s Algorithm) Algorithm Implementation In C++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to find maximum subarray sum
int maxSubArray(vector<int>& arr, int n) {
    int maxSum = arr[0];
    int currSum = arr[0];
    for(int i = 1; i < n; i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

// Function to print array
void printArray(vector<int>& arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array: ";
    printArray(arr, n);
    int result = maxSubArray(arr, n);
    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}

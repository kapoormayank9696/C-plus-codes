// LeetCode Problem 164: Maximum Gap
#include<iostream>
#include<vector>
using namespace std;

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    vector<int> output(n); // output array
    int count[10] = {0}; // count array for digits (0 to 9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to implement Radix Sort
int radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr, n);

    // Do counting sort for every digit. exp is 10^i where i is the current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10){
        countingSort(arr, n, exp);
    }
    int maxGap=0;
    for(int i=1;i<n;i++){
        maxGap=max(maxGap,arr[i]-arr[i-1]);
    }
    return maxGap;
}

// Function to find the Maximum Gap
int maximumGap(int nums[],int n) {
    int result=radixSort(nums,n);
    return result;
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    cout << "Enter number of elements: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    printArray(arr, n);

    int result=maximumGap(arr, n);
    cout<<"Maximum Gap From Sorted Array: "<<result<<endl;

    return 0;
}

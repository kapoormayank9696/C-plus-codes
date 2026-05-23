// Check if an array is a rotation of a sorted array Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Function to check if the given array is a rotation of a sorted array
bool isRotatedSorted(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[(i + 1) % n]) {
            count++;
        }
    }
    return count <= 1; 
}

// Main function
int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "The array is a rotation of a sorted array." << boolalpha << isRotatedSorted(arr, n) << endl;
    return 0;
}

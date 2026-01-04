// Merge two sorted arrays into a single sorted array in C++
#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }cout << "\n";
}

// Function to merge two sorted arrayarr
void MergeSort(int arr[], int j, int arr1[], int k){
    int p=j-1;
    int q=k-1;
    int r=j+k-1;
    int merged[r];
    while(p >= 0 && q >= 0){
        if(arr[p] > arr1[q]){
            merged[r] = arr[p];
            p--;
            r--;
        } else {
            merged[r] = arr1[q];
            q--;
            r--;
        }
    }while(p >= 0){
         merged[r] = arr[p];
         r--;
         p--;
    }while(q >= 0){
        merged[r] = arr1[q];
        r--;
        q--;
    } 
    printArray(merged, j+k);
}

// Main function
int main(){
    int arr[] = {1, 3, 5, 7};
    int j = sizeof(arr)/sizeof(arr[0]);
    int arr1[] = {2, 4, 6, 8, 10};
    int k = sizeof(arr1)/sizeof(arr1[0]);
    cout << "First Array: ";
    printArray(arr, j);
    cout << "Second Array: ";
    printArray(arr1, k);
    cout<<"After Merging Two Sorted Arrays: ";
    MergeSort(arr, j, arr1, k);
    return 0;
}

// Insertion Sort Algorithm in C++
#include<iostream>
using namespace std;

// Function to print the array
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

// Function to perform Insertion Sort Algorithm
void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int k = arr[i];
        while(j >= 0 && arr[j] > k){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
}

// Main function
int main(){
    int arr[] = {98,-2,0,8,542};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting an array : ";
    printArray(arr,n);
    InsertionSort(arr,n);
    cout<<"After sorting an array : ";
    printArray(arr,n);
    return 0;
}

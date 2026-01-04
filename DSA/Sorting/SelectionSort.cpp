// Selection Sort Algorithm in C++
#include<iostream>
using namespace std;

// Function to print the array
void printArray(int arr[] ,int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

// Function to perform Selection Sort Algorithm
void SelectionSort(int arr[] ,int n){
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        int c = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = c;
    }
}

// Main function
int main(){
    int arr[] = {2,0,-45,89,1,534};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Before sorting an array : ";
    printArray(arr,n);
    selectionsort(arr,n);
    cout<<"After sorting an array : ";
    printArray(arr,n);
    return 0;
}

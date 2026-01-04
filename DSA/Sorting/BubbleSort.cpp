// Bubble Sort Algorithm in C++
#include<iostream>
using namespace std;

// Function to print the array
void printArray(int arr[],int n){
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

// Function to perform Bubble Sort Algorithm
void BubbleSort(int arr[],int n){
   for(int i=0;i<n;i++){
       for(int j=0;j< n-1;j++){
           if(arr[j] > arr[j+1]){
               int c = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = c;
           }
       }
   }
}

// Main function
int main(){
    int arr[] = {-5,0,89,-9,42,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting an array : ";
    printArray(arr,n);
    Bubblesort(arr,n);
    cout<<"After sorting an array : ";
    printArray(arr,n);
    return 0;
}

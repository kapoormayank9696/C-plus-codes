// Binary Search Algorith in C++
#include<iostream>
#include<vector>
using namespace std;

// Function For Print The Array Elements
void printArray(int arr[],int k){
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"-----------------"<<endl;
}

// Function For Searching The Target Element
int BinarySearch(int arr[],int target,int k){
    int start=0;
    int end=k-1;
    for(int i=0;i<k;i++){
        int mid=(start+end)/2;
        if(target < arr[mid]){
            start=mid+1;
        }
        else if(target > arr[mid]){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

// Main Function
int main(){
    int x;  // User Input No. of Terms
    cout<<"Input Number of Terms in An Array : ";
    cin>>x;  // Define Array With Elements
    int arr[x];  // Input Value of Array By User
    cout<<"Enter "<<x<<" Elements OF An Array : ";
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    int target;  // Sizeof Array
    int k=sizeof(arr)/sizeof(arr[0]);
    cout<<"Print Binary Search Array : ";   // Print Array Elemets
    printArray(arr,k);  // Input Target Element
    cout<<"Input Target Element : ";
    cin>>target;
    cout<<"Binary Searching Result"<<endl;  // Call The Function For Searching
    int result = BinarySearch(arr,target,k);
    if(result ==-1){
        cout<<"Target Element Cannot Exist In An Array"<<endl;
    }
    else{
        cout<<"Target Element At Index : "<<result<<endl;
    }
    return 0;
}
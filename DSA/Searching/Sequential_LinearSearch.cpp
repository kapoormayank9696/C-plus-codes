// Sequential / Linear Search Algorithm in C++
#include<iostream>
#include<vector>
using namespace std;

// Function For PrintThe Array Elements
void printArray(int arr[],int k){
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"------------------"<<endl;
}

// Function For Searching The Target Element
int linearSearch(int arr[],int k,int target){
    for(int i=0;i<k;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

// Main Function
int main(){
    int x;
    // User Input No. of Terms
    cout<<"Input Number of Terms in An Array : ";
    cin>>x;
    // Define Array With Elements
    int arr[x];
    // Input Value of Array By User
    cout<<"Enter "<<x<<" Elements OF An Array : ";
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Print The Sequetial Array : ";
    // Sizeof Array
    int k=sizeof(arr)/sizeof(arr[0]);
    // Call Function For PrintArray Elements
    printArray(arr,k);
    // Input The Target Element
    cout<<"Input Target element : ";
    cin>>target;
    cout<<"After Searching Target Element From Sequential Array Result"<<endl;
    // Call The Function For Searching The Target Element
    int result=linearSearch(arr,k,target);
    if(result ==-1){
        cout<<"Target Element Cannot Exist In An Array..";
    }else{
        cout<<"Target Element Exist At Index : "<<result<<endl;
    }
    return 0;
}
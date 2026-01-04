// Shell Sort Algorithm in C++
#include<iostream>
using namespace std;

// Function to print the array
void printArray(int arr[],int k){
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

// Function to perform Shell Sort Algorithm
void ShellSort(int arr[],int k){
    for(int gap=k/2;gap>0;gap=gap/2){
        for(int i=gap;i<k;i++){
            int temp=arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp;j=j-gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}

// Main function
int main(){
    int arr[]={12,-5,0,1,98,34,67};
    int k=sizeof(arr)/sizeof(arr[0]);
    cout<<"Print Array Before Sorting : ";
    printArray(arr,k);
    cout<<"After Applying Shell Sort Algorithm : ";
    ShellSort(arr,k);
    printArray(arr,k);
    return 0;
}

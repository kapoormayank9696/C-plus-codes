// Remove Duplicate Elements From An Array Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to remove the duplicate elements from an array
int removeDuplicate(int nums[],int size){
    int k=1;
    for(int i=1;i<size;i++) {
        if(nums[i] != nums[i-1]) {
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}

// Function to display the array
void printArray(int nums[],int size) {
    for(int i=0;i<size;i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

// Main function
int main() {
    int n;
    cout<<"Enter size of matrix: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Display the array: ";
    printArray(arr,n);
    int newSize=removeDuplicate(arr,n);
    cout<<"After remove the duplicate elements from array: ";
    printArray(arr,newSize);
    return 0;
}

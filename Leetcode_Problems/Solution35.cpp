// Leetcode Problem 35: Search Insert Position

#include<iostream>
using namespace std;

// Function to search insert position
int searchInsert(int nums[],int n,int target){
    int k=0;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            return i;
        }else if(nums[i]<target){
            k++;
        }
    }
    return k;
}

// Function To Display the array
void printArray(int nums[],int k){
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n"<<endl;
}

// Main function
int main(){
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    int nums[n];
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Print Array Elements: ";
    printArray(nums,n);
    cout<<"Enter target element: ";
    int target;
    cin>>target;
    int result=searchInsert(nums, n, target);
    cout<<"Insert Position Of Target Element: "<<result;
    return 0;
}
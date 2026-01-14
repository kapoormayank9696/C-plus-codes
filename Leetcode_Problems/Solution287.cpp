// LeetCode Problem 287: Find the Duplicate Number

#include<iostream>
#include<set>
using namespace std;

// Function to find the duplicate number in the array
int findDuplicate(int nums[],int n){
    set<int> list;
    for(int i=0;i<n;i++){
        int num=nums[i];
        if(list.count(num)){
            return num;
        }else{
            list.insert(num);
        }
    }
    return -1; // Placeholder return statement
}

// Function to print the array
void printArray(int arr[], int k){
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
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
    int result=findDuplicate(nums,n);
    cout<<"Duplicate Number: "<<result;
    return 0;  
}

// LeetCode Problem 561: Array Partition

#include<iostream>
#include<vector>
using namespace std;

// Method of sorting an array in ascending order
int arrayPairSum(int nums[],int n) {
    int maxVal=nums[0];
    int minVal=nums[0];
    for(int i=0;i<n;i++){
        if(nums[i]>maxVal){
            maxVal=nums[i];
        }
        if(nums[i]<minVal){
            minVal=nums[i];
        }
    }
    vector<int> count(maxVal-minVal+1,0);
    for(int i=0;i<n;i++){
        count[nums[i]-minVal]++;
    }
    int k=0;
    for(int i=0;i<count.size();i++){
        while(count[i] > 0){
            nums[k++]=i+minVal;
            count[i]--;
        }
    }
    int possibleSum=0;
    for(int i=0;i<n;i=i+2){
        possibleSum=possibleSum+nums[i];
    }
    return possibleSum;
}

// Function to print an array
void printArray(int nums[],int n){
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n"<<endl;
}

// Main function
int main(){
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    cout<<"Enter Elements: ";
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Original Array: ";
    printArray(nums,n);
    int result=arrayPairSum(nums,n);
    cout<<"Maximum sum from the minimum value from the pairs: "<<result<<endl;
}

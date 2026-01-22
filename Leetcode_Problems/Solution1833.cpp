// LeetCode Problem: 1833. Maximum Ice Cream Bars
#include<iostream>
using namespace std;

// Function to calculate the maximum number of ice cream bars that can be bought
int maxIceCream(int costs[], int coins, int n) {
    int max=costs[0];
    int min=costs[0];
    for(int i=0;i<n;i++){
        if(costs[i] > max){
            max=costs[i];
        }
        if(costs[i] < min){
            min=costs[i];
        }
    }
    int count[max-min+1]={0};
    for(int i=0;i<n;i++){
        count[costs[i]-min]++;
    }
    int l=max-min+1;
    int k=0;
    for(int i=0;i<l;i++){
        while(count[i] > 0){
            costs[k++]=i+min;
            count[i]--;
        }
    }
    int total=0;
    int sum=0;
    for(int i=0;i<l;i++){
        if(sum+costs[i] > coins)
        break;
        sum=sum+costs[i];
        total++;
    }
    return total;
}


// Function to print the array
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<endl;
}

// Main function
int main(){
    cout<<"Enter number of ice cream bars: ";
    int n;
    cin>>n;
    int costs[n];
    cout<<"Enter costs of each ice cream bar: ";
    for(int i=0;i<n;i++){
        cin>>costs[i];
    }
    cout<<"Enter total coins available: ";
    int coins;
    cin>>coins;
    cout<<"Costs of ice cream bars: ";
    printArray(costs,n);
    int result=maxIceCream(costs,coins,n);
    cout<<"Maximum number of ice cream bars that can be bought: "<<result<<endl;
    return 0;  
}
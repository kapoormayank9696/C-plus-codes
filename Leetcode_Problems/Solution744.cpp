// LeetCode Problem 744: Find Smallest Letter Greater Than Target
#include<iostream>
#include <algorithm> // for std::sort
using namespace std;

// Method to perform find smallest letter greater than target
char nextGreatestLetter(char letters[],int n, char target) {
    int start=0,end=n-1;
    while(start <= end){
        int mid=start+(end-start)/2;
        if(letters[mid] <= target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return letters[start % n];
}

// Method to print character array
void printArray(char letters[], int n){
    for(int i=0;i<n;i++){
        cout<<letters[i]<<" ";
    }
    cout<<"\n"<<endl;
}

// Main function
int main(){
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    cout<<"Enter character elements: ";
    char letters[n];
    for(int i=0;i<n;i++){
        cin>>letters[i];
    }
    // Sort the array
    sort(letters,letters+n);
    cout<<"Display the character array: ";
    printArray(letters,n);
    char target;
    cout<<"Enter target character: ";
    cin>>target;
    char result=nextGreatestLetter(letters,n,target);
    cout << "Greater character of the target character: " << result << endl;
    return 0;
}


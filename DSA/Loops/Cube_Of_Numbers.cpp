// Cube Of N Numbers Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Main function
int main(){
    int n;
    cout<<"Enter the number of natural numbers to cube: ";
    cin>>n;
    
    int sum = 0;
    cout<<"\nThe cube of natural numbers up to "<<n<<" terms are :"<<endl;
    for(int i=1; i<=n; i++){
        cout<<"Number is: "<<i<<" and its cube of the: "<<i*i*i<<endl; // Printing the cube of the ith natural number
        sum += i*i*i; // Adding the cube of the ith natural number
    }   
    cout<<"\nThe sum of the cubes of the first "<<n<<" natural numbers is: "<<sum<<endl;
    
    return 0;
}

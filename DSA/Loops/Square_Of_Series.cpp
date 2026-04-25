// Square Of Series Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Main function
int main(){
    int n;
    cout<<"Enter the number of natural numbers to sum: ";
    cin>>n;
    
    int sum = 0;
    cout<<"\nThe square natural numbers up to "<<n<<" terms are :";
    for(int i=1; i<=n; i++){
        cout<<i*i<<" "; // Printing the square of the ith natural number
        sum += i*i; // Adding the square of the ith natural number
    }   
    cout<<"\nThe sum of the first "<<n<<" natural numbers is: "<<sum<<endl;
    
    return 0;
}

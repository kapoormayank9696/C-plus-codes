// Even Natural Numbers Sum Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Main function
int main(){
    int n;
    cout<<"Enter the number of even natural numbers to sum: ";
    cin>>n;
    
    int sum = 0;
    cout<<"The first "<<n<<" even natural numbers are: ";
    for(int i=1; i<=n; i++){
        sum += (2*i); // Adding the ith even number
        cout<<(2*i)<<" "; // Print the ith even number
    }   
    cout<<"\nThe sum of the first "<<n<<" even natural numbers is: "<<sum<<endl;
    
    return 0;
}

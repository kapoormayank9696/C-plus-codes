// Odd Natural Numbers Sum Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Main function
int main(){
    int n;
    cout<<"Enter the number of odd natural numbers to sum: ";
    cin>>n;
    
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += (2*i - 1); // Adding the ith odd number
    }   
    cout<<"The sum of the first "<<n<<" odd natural numbers is: "<<sum<<endl;
    
    return 0;
}


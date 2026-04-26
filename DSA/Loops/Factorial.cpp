// Factorail Of A Number Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Main function
int main(){
    int n;
    cout<<"Enter a number to find its factorial: ";
    cin>>n;
    
    unsigned long long factorial = 1; // Using unsigned long long to handle large factorials
    for(int i=1; i<=n; i++){
        factorial *= i; // Multiplying the ith number to the factorial
    }   
    cout<<"\nThe factorial of "<<n<<" is: "<<factorial<<endl;
    
    return 0;
}


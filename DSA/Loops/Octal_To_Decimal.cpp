// Octal to Decimal Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to convert Octal to Decimal
void octalToDecimal(int n) {
    int remainder,i=1,sum=0;
    while(n != 0){
        remainder=n%10;
        sum=sum+remainder*i;
        n=n/10;
        i=i*8;
    }
    cout<<sum;
}

// Main function
int main() {
    int n;
    cout<<"Enter a number to convert : ";
    cin>>n;
    cout<<"The Decimal of "<<n<<" is ";
    octalToDecimal(n);
    return 0;
}


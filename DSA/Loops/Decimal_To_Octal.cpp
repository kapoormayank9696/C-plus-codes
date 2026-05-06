// Decimal to Octal Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to convert Decimal to Octal
void decimalToOctal(int n) {
    int remainder=0,place=1,sum=0;
    while(n > 0){
        remainder=n%8;
        sum=sum+remainder*place;
        place=place*10;
        n=n/8;
    }
    cout<<sum;
}

// Main function
int main() {
    int n;
    cout<<"Enter a number to convert : ";
    cin>>n;
    cout<<"The Octal of "<<n<<" is ";
    decimalToOctal(n);
    return 0;
}


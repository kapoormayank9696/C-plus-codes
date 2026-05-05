// LCM Using HCF Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to find the LCM from two numbers
int lcm(int a,int b) {
    int hcf=0,lcm=0;
    int k=(a>b)?a:b;
    for(int i=1;i<=k;i++) {
        if(a%i==0 && b%i==0) {
            hcf=i;
        }
    }
    lcm=(a*b)/hcf;
    return lcm;
}

// Main function
int main() {
    int a,b;
    cout<<"Input 1st number for LCM: ";
    cin>>a;
    cout<<"Input 2nd number for LCM: ";
    cin>>b;
    int result=lcm(a,b);
    cout<<"The LCM of "<<a<<" and "<<b<<" is : "<<result;
}


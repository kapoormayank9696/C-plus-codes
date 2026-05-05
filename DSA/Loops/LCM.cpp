// LCM Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to find the LCM from two numbers
int lcm(int a,int b) {
    int lcm=0;
    int k=(a>b)?a:b;
    for(int i=k;;i+=k) {
        if(i%a==0 && i%b==0) {
            lcm=i;
            break;
        }
    }
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

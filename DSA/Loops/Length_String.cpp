// String Of Length Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Input a string : ";
    cin>>str;

    int sum=0;
    for(int i=0;i<str.length();i++) {
        sum=sum+1;
    }
    cout<<"The string contains "<<sum<<" number of characters."<<endl;
    cout<<"So, the length of the string welcome is : "<<sum<<endl;
    return 0;
}


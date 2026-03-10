// Count Length Of String Algorithm Implementation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    // Count lenght of string
    cout<<"Length of string:"<<str.length()<<endl;
    return 0;
}



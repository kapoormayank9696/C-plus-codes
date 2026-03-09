// Convert String into UpperCase Algorithm Implementation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    // Convert each character to uppercase
    for(int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    cout<<"String is uppercase: "<<str<<endl;
    return 0;
}



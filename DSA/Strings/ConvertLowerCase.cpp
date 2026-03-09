// Convert String into LowerCase Algorithm Implementation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    // Convert each character to lowercase
    for(int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    cout<<"String is lowercase: "<<str<<endl;
    return 0;
}



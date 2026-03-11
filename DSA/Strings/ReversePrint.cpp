// Reverse Print String Algorithm Implementation In C++
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    // Print original string
    cout<<"Original String: "<<str<<endl;
    // Reverse the string using the reverse() function from algorithm library
    string reverse_str = str;  // Create a copy of the original string
    // Reverse the string in place
    reverse(reverse_str.begin(), reverse_str.end());  

    // Print reversed string
    cout<<"Reverse the user input string: "<<reverse_str<<endl;
    return 0;
}

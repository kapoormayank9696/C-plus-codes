// Check String is Palindrome Or Not Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to check string is palindrome or not
bool palindrome(string str) {
    int n=str.length();
    for(int i=0;i<n/2;i++){
        if(str[i] != str[n-i-1]){
            return false;
        }
    }
    return true;
}

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    cout<<"Display the string: "<<str<<endl<<endl;
    if(palindrome(str)){
        cout<<"Yes, string is palindrome...."<<endl;
    }else {
        cout<<"No, string is not palindrome...."<<endl;
    }
    return 0;
}


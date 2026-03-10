// Split The String Algorithm Implementation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    // Split The String
    cout<<"String is split:"<<endl;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            cout<<endl;   // new word on new line
        }
        else {
            cout<<str[i];
        }
    }
    return 0;
}



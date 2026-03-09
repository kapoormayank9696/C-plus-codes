// Check String is Lower or not Algorithm Implementation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Function to check lowercase
bool isLowerCase(string str) {
    for(int i = 0; i < str.length(); i++) {
        if(isalpha(str[i]) && !islower(str[i])) {
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
    if(isLowerCase(str)) {
        cout<<"String is lowercase.... \n"<<endl;
    }else {
        cout<<"String is not lowercase....\n"<<endl;
    }
    return 0;
}



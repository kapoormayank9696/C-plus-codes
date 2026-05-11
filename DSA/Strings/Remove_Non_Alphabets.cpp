// Remove Non-Alphabets Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Fumction to perform Remove Non Alphabets
string removeAlphabets(string str) {
    string result= "";

    for(int i=0;i<str.size();i++) {
        if((str[i] >= 'a' && str[i] <= 'z') ||
           (str[i] >= 'A' && str[i] <= 'Z')) {
            result=result+str[i];
        }
    }
    return result;
}

// Main function
int main() {
    string str;
    cout<<"Input the string : ";
    cin>>str;
    string output = removeAlphabets(str);

    cout << "String after removing non-alphabets: " << output;

    return 0;
}

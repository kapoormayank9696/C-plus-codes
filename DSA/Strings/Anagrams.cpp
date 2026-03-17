// Check String is anagrams or not Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to check strings are anagrams or not
bool isAnagrams(string str,string str1) {
    // Check the length of strings
    if(str.length() != str1.length()){
        return false;
    }
    // Define the array and intialized
    int count[256]={0};
    for(char c:str) {
        count[c]++;
    }
    for(char c:str1) {
        count[c]--;
    }
    for(int i=0;i<256;i++) {
        if(count[i] != 0) {
            return false;
        }
    }
    return true;
}

// Main function
int main() {
    string str,str1;
    cout<<"Enter first string: ";
    getline(cin,str);
    cout<<"Enter second string: ";
    getline(cin,str1);
    cout<<"\nDisplay first string: "<<str<<endl;
    cout<<"Display second string: "<<str1<<endl;
    if(isAnagrams(str,str1)) {
        cout<<"\nYes ,strings are anagrams...."<<endl;
    }else {
        cout<<"\nNo ,strings are not anagrams...."<<endl;
    }
    return 0;
}


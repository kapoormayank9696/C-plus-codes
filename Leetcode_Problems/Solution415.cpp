// LeetCode Problem 415 : Add Strings
#include<iostream>
#include<algorithm>
using namespace std;
// Function to add the strings 
string addStrings(string num1, string num2) {
    // It's store the result of two strings
    string result = "";
    // store the size into the variables
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        // Take the value from string and store an add
        if(i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if(j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        // Store the digit
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    // Reverse the string
    reverse(result.begin(), result.end());
    return result;
}

// Main function
int main() {
    string str,str1;
    cout<<"Enter first string: ";
    getline(cin,str);
    cout<<"Enter second string: ";
    getline(cin,str1);
    cout<<"First string: "<<str<<endl;
    cout<<"Second string: "<<str1<<endl;
    cout<<"Sum of two strings: "<<addStrings(str,str1)<<endl;
    return 0;
}


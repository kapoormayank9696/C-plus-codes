// Subset Generation Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to generate subsets
void generateSubsets(string str, string curr, int index) {
    if(index == str.size()) {
        cout << curr << endl;
        return;
    }
    // Include the current character
    generateSubsets(str, curr + str[index], index + 1);
    // Exclude the current character
    generateSubsets(str, curr, index + 1);
}

// Main function
int main() {
    cout << "Enter a string: ";
    string str;
    cin >> str;
    cout << "Subsets of the string are: " << endl;
    generateSubsets(str, "", 0);
    return 0;
}


// Permutation Generation for a String using Backtracking Algorithm Implementation in C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to generate permutations using backtracking
void permute(string& str, vector<string>& result, string& temp, vector<bool>& used) {
    if(temp.size() == str.size()) {
        result.push_back(temp);
        return;
    }
    for(int i = 0; i < str.size(); i++) {
        if(used[i]) continue; // Skip used characters
        used[i] = true; // Mark character as used
        temp.push_back(str[i]); // Include character
        permute(str, result, temp, used); // Recursive call
        temp.pop_back(); // Backtrack (remove last character)
        used[i] = false; // Mark character as unused
    }
}

// Main function
int main() {
    cout << "Enter a string: ";
    string str;
    cin >> str;
    vector<string> result;
    string temp;
    vector<bool> used(str.size(), false);
    permute(str, result, temp, used);
    cout << "Permutations are:\n";
    for(const auto& permutation : result) {
        cout << permutation << "\n";
    }
    return 0;
}


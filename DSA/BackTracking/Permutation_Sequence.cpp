// Permutation Sequence Generation using Backtracking Algorithm Implementation in C++
#include <iostream>
#include <vector>
using namespace std;

string getPermutation(int n, int k) {
    // Create a vector (like ArrayList)
    vector<int> temp;
    // Create factorial array
    vector<int> fact(n);
    fact[0] = 1;
    // Compute factorial values
    for(int i = 1; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    // Store numbers from 1 to n
    for(int i = 1; i <= n; i++) {
        temp.push_back(i);
    }
    // Convert k to 0-based index
    k--;
    // Result string
    string result = "";
    // Build permutation
    for(int i = n; i > 0; i--) {
        int index = k / fact[i - 1];
        result += to_string(temp[index]);
        // Remove used number
        temp.erase(temp.begin() + index);
        // Update k
        k = k % fact[i - 1];
    }
    return result;
}

// Main function
int main() {
    int n, k;
    cout << "Enter n (number of elements): ";
    cin >> n;
    cout << "Enter k (permutation index): ";
    cin >> k;
    string permutation = getPermutation(n, k);
    cout << "The " << k << "-th permutation sequence is: " << permutation << endl;
    return 0;
}

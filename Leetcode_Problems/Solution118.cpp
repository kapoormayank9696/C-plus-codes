// LeetCode Problem 118: Pascal's Triangle
#include <iostream>
#include <vector>
using namespace std;

// Class to generate Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows); // Initialize the triangle with the number of rows
        for (int i = 0; i < numRows; ++i) {
            triangle[i].resize(i + 1, 1); // Resize each row and initialize with 1's
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Update the current element by adding the two elements above it
            }
        }
        return triangle;
    }
};

// Main function
int main() {
    Solution solution;
    int numRows = 5; // Example number of rows
    vector<vector<int>> result = solution.generate(numRows);
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}



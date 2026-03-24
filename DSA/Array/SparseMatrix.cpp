// Sparse Matrix Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Main function
int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    // Count non-zero elements
    int count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0)
                count++;
        }
    }
    // Triplet representation
    vector<vector<int>> sparse;
    // First row: metadata
    sparse.push_back({rows, cols, count});
    // Store non-zero elements
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse.push_back({i, j, matrix[i][j]});
            }
        }
    }
    // Display sparse matrix
    cout << "\nSparse Matrix (Triplet Form):\n";
    for(auto row : sparse) {
        cout << row[0] << " " << row[1] << " " << row[2] << endl;
    }
    return 0;
}

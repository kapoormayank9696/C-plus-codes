// Simple Sudoku 3*3 by Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to check if it's safe to place a number in the given cell
bool isSafe(int board[3][3], int row, int col, int num) {
    // Check if the number is not in the current row and column
    for (int x = 0; x < 3; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }
    return true;
}
// Recursive function to solve the Sudoku board
bool solve(int board[3][3]) {
    int row, col;
    bool isEmpty = false;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    // No empty space left, Sudoku solved
    if (!isEmpty) {
        return true;
    }
    // Try placing numbers from 1 to 3 in the empty cell
    for (int num = 1; num <= 3; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num; // Place the number
            if (solve(board)) { // Recur to solve the rest of the board
                return true;
            }
            board[row][col] = 0; // Backtrack
        }
    }
    return false; // Trigger backtracking
}

// Function to print the Sudoku board
void printBoard(int board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Enter the Sudoku board (use 0 for empty cells):" << endl;
    printBoard(board);
    cout << "Solving the Sudoku..." << endl;
    if(solve(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}


// Leetcode Problem 37: Sudoku Solver
#include <iostream>
using namespace std;
// Function to check if it's safe to place a number in the given cell
bool isSafe(char board[9][9], int row, int col, char num) {
    // Check if the number is not in the current row and column
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }
    // Check if the number is not in the current 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Recursive function to solve the Sudoku board
bool solveSudoku(char board[9][9]) {
    int row, col;
    bool isEmpty = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
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
    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = '1'; num <= '9'; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num; // Place the number
            if (solveSudoku(board)) { // Recur to solve the rest of the board
                return true;
            }
            board[row][col] = '.'; // Backtrack
        }
    }
    return false; // Trigger backtracking
}

// Function to print the Sudoku board
void printBoard(char board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}



// Valid Sudoku Algorithm Implementation In C++
#include <iostream>
#include <vector>
using namespace std;

// Function to check if the given Sudoku board is valid
bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> row(9, vector<bool>(9, false));
    vector<vector<bool>> col(9, vector<bool>(9, false));
    vector<vector<bool>> box(9, vector<bool>(9, false));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == '.') continue;
            int num = board[i][j] - '1';
            int boxIndex = (i / 3) * 3 + (j / 3);
            if(row[i][num] || col[j][num] || box[boxIndex][num]) {
                return false;
            }
            row[i][num] = true;
            col[j][num] = true;
            box[boxIndex][num] = true;
        }
    }
    return true;
}

// Function to print the Sudoku board
void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
        ,{'.','8','.','.','.','.','.','4','.'}
    };
    if (isValidSudoku(board)) {
        cout << "\nThe Sudoku board is valid." << endl;
    } else {
        cout << "\nThe Sudoku board is invalid." << endl;
    }
    return 0;
}

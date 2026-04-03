// Array Part 2 Algorithm Implementation In C++
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to determine if the game can be won
bool canWin(vector<int>& game, int leap, int i) {
    // Base case: If index goes beyond array → win
    if (i >= game.size()) return true;
    // Base case: invalid position or blocked cell
    if (i < 0 || game[i] == 1) return false;
    // Mark as visited
    game[i] = 1;
    // Try all possible moves
    return canWin(game, leap, i + leap) ||
           canWin(game, leap, i + 1) ||
           canWin(game, leap, i - 1);
}

// Wrapper function
bool checkGame(vector<int>& game, int leap) {
    return canWin(game, leap, 0);
}

// Main function
int main() {
    int q;
    cin >> q;
    while (q-- > 0) {
        int n, leap;
        cin >> n >> leap;
        vector<int> game(n);
        for (int i = 0; i < n; i++) {
            cin >> game[i];
        }
        cout << (checkGame(game, leap) ? "YES" : "NO") << endl;
    }
    return 0;
}

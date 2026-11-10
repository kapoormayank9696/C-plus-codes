// Leetcode 1267: Count Servers that Communicate
#include <iostream>
using namespace std;

// Count Servers that Communicate Function
int countServers(int grid[][3], int rows, int cols) {
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == 1) {
                bool found = false;

                // Check same row
                for (int k = 0; k < rows; k++) {
                    if (k != i && grid[k][j] == 1) {
                        found = true;
                        break;
                    }
                }

                // Check same column
                for (int k = 0; k < cols; k++) {
                    if (k != j && grid[i][k] == 1) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Main function
int main() {
    int grid[3][3] = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    int rows = sizeof(grid) / sizeof(grid[0]);
    int cols = sizeof(grid[0]) / sizeof(grid[0][0]);
    int result = countServers(grid, rows, cols);
    cout << "Count of servers that communicate: " << result << endl;
    return 0;
}

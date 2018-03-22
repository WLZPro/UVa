#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string caseName;

bool grid[10][10];

int backtrack(int row, bool grid2[10][10]) {
    if (row == 9) {
        for (int i = 0; i < 10; i++) {
            if (grid2[9][i]) return 101;
        }
        return 0;
    }
    int moves = 0;
    for (int i = 0; i < 10; i++) {
        if (grid2[row][i]) {
            moves++;
            grid2[row][i] = 0;
            grid2[row + 1][i] = !grid2[row + 1][i];
            if (row < 8) grid2[row + 2][i] = !grid2[row + 2][i];
            if (i > 0) grid2[row + 1][i - 1] = !grid2[row + 1][i - 1];
            if (i < 9) grid2[row + 1][i + 1] = !grid2[row + 1][i + 1];
        }
    }
    return moves + backtrack(row + 1, grid2);
}

int main() {
    while (getline(cin, caseName), caseName != "end") {
        for (int i = 0; i < 10; i++) {
            string row; 
            getline(cin, row);
            for (int j = 0; j < 10; j++) {
                grid[i][j] = row[j] == 'O';
            }                                  
        }
        bool copy[10][10];
        memcpy(copy, grid, sizeof copy);
        int ans = 1e+9;
        for (int mask = 0; mask < (1 << 10); mask++) {
            memcpy(grid, copy, sizeof grid);
            int moves = 0;
            for (int i = 0; i < 10; i++) {
                if (mask & (1 << i)) {
                    moves++;
                    grid[0][i] = !grid[0][i];
                    grid[1][i] = !grid[1][i];
                    if (i) grid[0][i - 1] = !grid[0][i - 1];
                    if (i < 9) grid[0][i + 1] = !grid[0][i + 1];
                }
            }
            ans = min(ans, moves + backtrack(0, grid));
        }
        if (ans > 100) {
            cout << caseName << " " << -1 << "\n";
        } else {
            cout << caseName << " " << ans << "\n";
        }
    }
    return 0;
}
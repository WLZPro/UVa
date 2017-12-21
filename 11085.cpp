#include <cstdlib>
#include <stdio.h>
using namespace std;
int row[8], row2[8], min = 9;

bool place(int r, int col) {
    for (int prev = 0; prev < col; prev++) {
        if (row2[prev] == r || (abs(row2[prev] - r)) == abs(prev - col)) {
            return false;
        }
    }
    return true;
}

void backtrack(int col) {
    if (col == 8) {
        int dist = 0;
        for (int i = 0; i < 8; i++) {
            if (row[i] != row2[i]) {
                dist ++;
            }
        }
        if (dist < min) {
            min = dist;
        }
        return;
    }
    for (int r = 0; r < 8; r++) {
        if (place(r, col)) {
            row2[col] = r;
            backtrack(col + 1);
        }
    }
}
int main() {
    int caseNow = 1 ,a;
    while (scanf("%d", &a) != EOF) {
        row[0] = a - 1;
        for (int i = 1; i < 8; i++) {
            scanf("%d", &a);
            row[i] = a - 1;
        }
        backtrack(0);
        printf("Case %d: %d\n", caseNow, min);
        min = 9;
        ++caseNow;
    }
}

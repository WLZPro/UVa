#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits>

using namespace std;

int X;
int vals[10][1000]; 
int memo[1505 * 11];

int neededFuel(int i, int height) {
    if (i == X / 100) {
        if (height != 0) return 999999999;
        return 0;
    }
    int index = height * 1000 + i;
    if (memo[index] != -1) return memo[index];
    int res;
    res = neededFuel(i + 1, height) - vals[height][i] + 30;
    if (height > 0) {
        res = min(res, neededFuel(i + 1, height - 1) - vals[height][i] + 20);
    }
    if (height < 9) {
        res = min(res, neededFuel(i + 1, height + 1) - vals[height][i] + 60);
    }
    return memo[index] = res;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        memset(memo, -1, sizeof memo);
        scanf("%d", &X);
        for (int i = 10; i > 0; i--) {
            for (int j = 0; j < X / 100; j++) {
                scanf("%d", &vals[i - 1][j]);
            }
        }
        printf("%d\n\n", neededFuel(0,0));
    }
}
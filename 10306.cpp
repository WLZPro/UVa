
#include <stdio.h>
#include <algorithm>
#include <limits>
#include <string.h>

using namespace std;

int eCoins[305];
int conventionalValues[305];
int m, S;
int* memo = new int[90005];

int coinChange(int x,int y) {
    if (x * x + y * y == S * S) return 0;
    if (x * x + y * y > S * S) return std::numeric_limits<int>::max();
    int index = x * S + y;
    if (memo[index] != -1) return memo[index];
    int res = std::numeric_limits<int>::max();

    for (int i = 0; i < m; i++) {
        int counts = coinChange(x + eCoins[i], y + conventionalValues[i]);
        res = min(res, counts);
    }

    return  memo[index] = res < std::numeric_limits<int>::max() ? res + 1 : res;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &m, &S);
        memset(memo, -1, sizeof (int) * 90005);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &conventionalValues[i], &eCoins[i]);
        }

        int nbrCoins = coinChange(0, 0);
        if (nbrCoins < std::numeric_limits<int>::max()) {
            printf("%d\n", nbrCoins);
        } else {
            printf("not possible\n");
        }
    }
    delete memo;
}
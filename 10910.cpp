#include <cstdio>
#include <cstring>

int memo[2][75];

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        memset(memo, 0, sizeof memo);
        int n, p, t;
        scanf("%d %d %d", &n, &t, &p);
        int cur = 1;
        for (int i = p; i <= t; i++) memo[0][i]++;
        for (int i = 1; i < n; i++) {
            memset(memo[cur], 0, sizeof memo[cur]);
            for (int j = 0; j <= t; j++) {
                if (memo[!cur][j]) {
                    for (int k = p; k <= t; k++) {
                        if (j + k <= t) {
                            memo[cur][j + k] += memo[!cur][j];
                        }
                    }
                }
            }
            cur = !cur;
        }
        printf("%d\n", memo[!cur][t]);
    }       
    return 0;
}
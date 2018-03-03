#include <bits/stdc++.h>
using namespace std;

int n, ok;

int x[20], y[20];
double dist[20][20];

double memo[1 << 16];

bitset<(1 << 16)> flagged;

double match(int mask) {
    if (mask == ok) return 0.0;
    if (flagged[mask]) return memo[mask];
    double ans = 1000000000.0;
    int pos = (~mask) & ok;
    while (pos) {
        int p = pos & -pos;
        pos -= p;
        int i = log2(p);
        for (int j = 0; j < 2 * n; j++) {
            if (i != j && !(mask & (1 << j))) {
                ans = min(ans, dist[i][j] + match(mask | (1 << i) | (1 << j)));
            }
        }
    }
    flagged[mask] = 1;
    return memo[mask] = ans;
}

int main() {
    int caseNow = 1;
    while (scanf("%d", &n), n) {
        memset(dist, 0, sizeof dist);
        flagged.reset();
        for (int i = 0; i < 2 * n; i++) {
            scanf("%*s %d %d", &x[i], &y[i]);
        }
        ok =  (1 << (2 * n)) - 1;
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = i + 1; j < 2 * n; j++) {
                dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
                dist[j][i] = dist[i][j];
                //printf("%d %d: %.2f\n", i, j, dist[i][j]);
            }
        }
        printf("Case %d: %.2f\n", caseNow++, match(0));
    }
}
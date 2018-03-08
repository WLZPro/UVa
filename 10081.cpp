#include <bits/stdc++.h>
using namespace std;

int n, k;

double memo[105][15];
double rate;

bool vis[105][15];

double solve(int i, int t) {
    if (t < 0 || t > k) return 0;
    if (i == n) return 1;
    if (vis[i][t]) return memo[i][t];
    double ans = 0;
    if (i == 0) {
        for (int j = 0; j <= k; j++) {
            ans += solve(1, j) / rate;

        }
    } else {
        ans += solve(i + 1, t) / rate;
        ans += solve(i + 1, t - 1) / rate;
        ans += solve(i + 1, t + 1) / rate;
    }
    vis[i][t] = 1;
    return memo[i][t] = ans;
}

int main() {
    while (scanf("%d %d", &k, &n) == 2) {
        memset(vis, 0, sizeof vis);

        rate = (double) (k + 1);
        double ans = (double) solve(0, 0);
        printf("%.5f\n", ans * 100.0);
    }
    return 0;
}
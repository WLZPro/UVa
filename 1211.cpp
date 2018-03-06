#include <bits/stdc++.h>
using namespace std;

int n, r;

int a[105];

bool c[10005];

double b, v, e, f;

double memo[10005][10005];

bool vis[10005][10005];

double solve(int i, int x) {
    if (i == a[n - 1]) return 0.0;
    if (vis[i][x]) return memo[i][x];
    double ans = 1000000000.0;
    double ve = 1.0 / (v - e * ((double) x - (double) r));
    double vf = 1.0 / (v - f * ((double) r - (double) x));
    double vThisTime = (x>=r)? ve:vf;
    if (c[i + 1]) {
        ans = min(ans, b + solve(i + 1, 0) + vThisTime);
    }
    ans = min(ans, solve(i + 1, x + 1) + vThisTime);
    vis[i][x] = 1;
    return memo[i][x] = ans;
}

int main() {
    while (scanf("%d", &n), n) {
        memset(vis, 0, sizeof vis);
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            a[i] = val;
            c[val] = 1;
        }
        scanf("%lf %d %lf %lf %lf", &b, &r, &v, &e, &f);
        printf("%.4f\n", solve(0, 0));
    }
    return 0;
}
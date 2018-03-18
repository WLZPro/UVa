#include <cstdio>
#include <cstring>

int max(int a, int b) {
    return a > b ? a : b;
}

int n;
int ok = (1 << 9) - 1;
int a[81], b[81], c[81], d[81];
int memo[81][1 << 9];
bool found;

int solve(int i, int mask) {
    if (mask == ok) {
        found = 1;
        return 0;
    }
    if (i == n) return -1;
    int &ans = memo[i][mask];
    if (ans != -1) return ans;
    ans = max(ans, solve(i + 1, mask));
    if (!(mask & (1 << a[i]) || mask & (1 << b[i]) || mask & (1 << c[i]))) {
        int tmp = solve(i + 1, mask | (1 << a[i]) | (1 << b[i]) | (1 << c[i]));
        if (tmp > -1) {
            ans = max(ans, d[i] + tmp);
        }
    }
    return ans;
}

int main() {
    int caseNow = 1;
    while (scanf("%d", &n), n) {
        memset(memo, -1, sizeof memo);
        found = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
            a[i]--;
            b[i]--;
            c[i]--;
        }
        int ans = solve(0, 0);
        printf("Case %d: %d\n", caseNow++, ans);
    }
    return 0;
}

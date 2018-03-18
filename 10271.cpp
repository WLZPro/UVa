#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int k, n;
int a[5005];
int memo[5005][1005];

int solve(int i, int k_left) {
    if (k_left == 0) return 0;
    if (i == n) return 1e+9;
    if (n - i < k_left * 3) return 1e+9;
    int &ans = memo[i][k_left];
    if (ans != -1) return ans;
    ans = 1e+9;
    ans = min(ans, solve(i + 1, k_left));
    if (i < n - 1) {
        ans = min(ans, (a[i] - a[i + 1]) * (a[i] - a[i + 1]) + solve(i + 2, k_left - 1));
    }
    //printf("%d %d %d\n", i, k_left, ans);
    return ans;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        memset(memo, -1, sizeof memo);
        scanf("%d %d", &k, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        printf("%d\n", solve(0, k + 8));
    }
    return 0;
}

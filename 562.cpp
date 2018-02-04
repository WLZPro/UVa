#include <bits/stdc++.h>
using namespace std;

int sz, full_sum, a[105], memo[105][50010];

int divide(int i, int sum_now) {
    if (i == sz) return abs(sum_now - (full_sum - sum_now));
    if (memo[i][sum_now] != -1) return memo[i][sum_now];
    int ans = min(divide(i + 1, sum_now + a[i]), divide(i + 1, sum_now));
    return memo[i][sum_now] = ans;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        memset(memo, -1, sizeof memo);
        memset(a, 0, sizeof a);
        full_sum = 0;
        scanf("%d", &sz);
        for (int i = 0; i < sz; i++) {
            scanf("%d", &a[i]);
            full_sum += a[i];
        }
        printf("%d\n", divide(0, 0));
    }
}
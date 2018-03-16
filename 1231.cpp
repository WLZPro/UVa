#include <bits/stdc++.h>
using namespace std;

int t, h, f;
int acorn[2005][2005];
int dp[2005];

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        memset(acorn, 0, sizeof acorn);
        scanf("%d %d %d", &t, &h, &f);
        for (int i = 0; i < t; i++) {
            int n;
            scanf("%d", &n);
            while (n--) {
                int val;
                scanf("%d", &val);
                acorn[i][val]++;
            }
        }
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < t; i++) {
            dp[h] = max(dp[h], acorn[i][h]);
        }
        for (int height = h - 1; height >= 0; height--) {
            for (int tree = 0; tree < t; tree++) {
                acorn[tree][height] += max(acorn[tree][height + 1], (height + f <= h) ? dp[height + f] : 0);
                dp[height] = max(dp[height], acorn[tree][height]);
            }
        }
        printf("%d\n", dp[0]);
    }
    return 0;
}
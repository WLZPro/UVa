#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (scanf("%d", &n) == 1) {
        int rect[105][105];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                scanf("%d", &val);
                rect[i][j] = val;
                if (i > 0) rect[i][j] += rect[i - 1][j];
                if (j > 0) rect[i][j] += rect[i][j - 1];
                if (i > 0 && j > 0) rect[i][j] -= rect[i - 1][j - 1];
            }
        }
        int ans = -127 * 100 * 101;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < n; l++) {
                        int res = rect[k][l];
                        if (i > 0) res -= rect[i - 1][l];
                        if (j > 0) res -= rect[k][j - 1];
                        if (i > 0 && j > 0) res += rect[i - 1][j - 1];
                        ans = max(ans, res);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
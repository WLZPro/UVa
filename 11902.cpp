#include <bits/stdc++.h>
using namespace std;

int n;

bool AdjMat[105][105], ans[105][105];

int flag;

bitset<105> vis, reachFromStart;

void dfs(int u) {
    if (u == flag) return;
    vis[u] = 1;
    for (int j = 0; j < n; j++) {
        if (AdjMat[u][j] && !vis[j] && j != flag) {
            dfs(j);
        }
    }
}

int main() {
    int TC, caseNow = 1;
    scanf("%d", &TC);
    while (TC--) {
        memset(AdjMat, 0, sizeof AdjMat);
        memset(ans, 0, sizeof ans);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            ans[i][i] = 1;
            for (int j = 0; j < n; j++) {
                int val;
                scanf("%d", &val);
                AdjMat[i][j] = val;
            }
        }
        flag = -1;
        dfs(0);
        reachFromStart.reset();
        for (int i = 0; i < n; i++) {
            ans[0][i] = vis[i];
            reachFromStart[i] = vis[i];
        }
        flag = 1;
        for (; flag < n; flag++) {
            vis.reset();
            dfs(0);
            for (int i = 1; i < n; i++) {
                if (reachFromStart[i]) {
                    ans[flag][i] = !vis[i];
                } else {
                    ans[flag][i] = 0;
                }
            }
        }
        vis.reset();
        printf("Case %d:\n", caseNow++);
        for (int i = 0; i < n; i++) {
            printf("+");
            for (int j = 0; j < 2 * n - 1; j++) printf("-");
            printf("+\n");
            for (int j = 0; j < n; j++) {
                if (ans[i][j] && reachFromStart[j]) {
                    printf("|Y");
                } else printf("|N");
            }
            printf("|\n");
        }
        printf("+");
        for (int j = 0; j < 2 * n - 1; j++) printf("-");
        printf("+\n");
    }
    return 0;
}
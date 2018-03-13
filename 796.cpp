#include <bits/stdc++.h>
using namespace std;
const int UNVISITED = -1;

int n;

vector<vector<int> > AdjList;
vector<int> dfs_low, dfs_num, dfs_parent;
int dfs_count, root_childs, dfs_root;

vector<pair<int, int> > ans;

void bridges(int u) {
    dfs_low[u] = dfs_num[u] = dfs_count++;
    for (int j = 0; j < (int) AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfs_root) root_childs++;
            bridges(v);
            if (dfs_low[v] > dfs_num[u]) {
                ans.push_back(make_pair(min(u, v), max(u, v)));
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    while (scanf("%d", &n) == 1) {
        dfs_count = 0;
        AdjList = vector<vector<int> >(n);
        dfs_low = vector<int>(n);
        dfs_num = vector<int>(n, UNVISITED);
        dfs_parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            int u, conn;
            scanf("%d (%d)", &u, &conn);
            for (int j = 0; j < conn; j++) {
                int v;
                scanf("%d", &v);
                AdjList[u].push_back(v);
            }
        }
        ans.clear();
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                dfs_root = i;
                root_childs = 0;
                bridges(i);
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d critical links\n", (int) ans.size());
        for (int i = 0; i < (int) ans.size(); i++) {
            printf("%d - %d\n", ans[i].first, ans[i].second);
        }
        printf("\n");
    }
    return 0;
}
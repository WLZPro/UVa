#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> adjList[2010];
vector<int> S;
int dfs_num[2010], dfs_low[2010], dfs_counter = 0, numSCC;
bool visited[2010], G = 1;
int N, M;
void SCC(int u) {
    dfs_low[u] = dfs_num[u] = dfs_counter++;
    S.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int)adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == -1)
            SCC(v);
        if (visited[v])                               
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        ++numSCC;        
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if (u == v) break;
        }
    } 
}

int main() {
    while (scanf("%d %d", &N, &M), N || M) {
        memset(dfs_num, -1, sizeof dfs_num);
        memset(dfs_low, -1, sizeof dfs_low);
        memset(visited, 0, sizeof visited);
        dfs_counter = 0;
        S.clear();
        G = 1;
        numSCC = 0;
        for (int i = 0; i < 2010; i++) {
            adjList[i].clear();
        }
        for (int i = 0; i < M; i++) {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            adjList[V].push_back(W);
            if (P == 2) {
                adjList[W].push_back(V);
            }
        }
        for (int i = 1; i <= N; i++) {
            if (dfs_num[i] == -1) {
                SCC(i);
            }
        }
        if (numSCC == 1) printf("1\n");
        else printf("0\n");
    }
}
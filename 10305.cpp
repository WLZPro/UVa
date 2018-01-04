#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> adjList[110];
vector<int> topoOrder;
bool visited[110];

void dfs(int j) {
    visited[j] = true;
    for (int i = 0; i < (int) adjList[j].size(); i++) {
        int val = adjList[j][i];
        if (!visited[val]) {
            dfs(val);
        }
    }
    topoOrder.push_back(j);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n || m) {
        for (int i = 0; i < 100; i++) {
            adjList[i].clear();
        }
        memset(visited, 0, sizeof visited);
        topoOrder.clear();
        for (int k = 0; k < m; k++) {
            int i, j;
            scanf("%d %d", &i, &j);
            adjList[i].push_back(j);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            printf("%d", topoOrder[i]);
            if (i) printf(" ");
        }
        printf("\n");
    }
}
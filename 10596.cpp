#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> AdjList[202];
int degree[502];
bool visited[502];
int cc_size;

void component_check(int u) {
    visited[u] = 1;
    for (int j = 0; j < (int) AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (u == v) {
            cc_size++;
        }
        if (!visited[v]) {
            component_check(v);
            cc_size++;
        }
    }
}

int main() {
    int V, E;
    while (scanf("%d %d",&V, &E) != EOF) {
        for (int i = 0; i < 202; i++) {
            AdjList[i].clear();
        }
        memset(degree, 0, sizeof degree);
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        bool eulerian = 1;
        for (int i = 0; i < V; i++) {
            if (degree[i] % 2 == 1 ) {
                eulerian = 0;
            }
        }
        if (!E) {
            eulerian = 0;
        }
        int cc = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cc_size = 0;
                component_check(i);
                if (cc_size > 0) {
                    cc++;
                }
            }
        }
        if (cc != 1 && eulerian) {
            eulerian = 0;
        } 
        printf("%s\n", eulerian ? "Possible" : "Not Possible");
    }
}
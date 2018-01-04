#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<int> adjList[210];
int color[210];

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int res = 0;
        memset(color, -1, sizeof color);
        for (int i = 0; i < 210; i++) {
            adjList[i].clear();
        }
        int V,E;
        scanf("%d %d", &V, &E);
        for (int i = 0; i < E; i++) {
            int f, t;
            scanf("%d %d", &f, &t);
            adjList[f].push_back(t);
            adjList[t].push_back(f);
        }
        
        bool bipartite = true;
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                int white = 0, black = 0;
                queue<int> q; q.push(i);
                color[i] = 0; white++;
                while(!q.empty() && bipartite) {
                    int u = q.front(); q.pop();
                    if ((int) adjList[u].size() == 0) black++;
                    for (int j = 0; j < (int) adjList[u].size(); j++) {
                        int e = adjList[u][j];
                        if (color[e] == -1) {
                            int colorVal = !color[u];
                            color[e] = colorVal;
                            if (colorVal) {
                                black++;
                            } else {
                                white++;
                            }
                            q.push(e);
                        } else if (color[e] == color[u]) {
                            bipartite = false; break;
                        }
                    }
                }
                if (!bipartite) break;
                res += black <= white ? black : white;
            }
        }
        if (!bipartite) printf("-1\n");
        else printf("%d\n", res);
    }
}
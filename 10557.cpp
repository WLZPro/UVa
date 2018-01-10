#include <stdio.h>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

vector<ii> adjList[102];
int energies[102], dist[102];
int cc[102];
bool visited[102];

void dfs(int v, int c) {
    cc[v] = c;
    visited[v] = 1;
    for (int j = 0; j < (int) adjList[v].size(); j++) {
        if (!visited[adjList[v][j].first]) {
            dfs(adjList[v][j].first, c);
        }
    }
}

int main() {
    int rooms;
    while (scanf("%d", &rooms), rooms != -1) {
        memset(energies, 0, sizeof energies);
        memset(dist, -1, sizeof dist);
        memset(cc, -1, sizeof cc);
        memset(visited, 0, sizeof visited);
        dist[1] = 100;
        for (int i = 0; i < 102; i++) {
            adjList[i].clear();
        }
        for (int i = 0; i < rooms; i++) {
            int energy, doorways;
            scanf("%d %d", &energy, &doorways);
            energies[i + 1] = energy;
            for (int j = 0; j < doorways; j++) {
                int room;
                scanf("%d", &room);
                adjList[i + 1].push_back(ii(room, 0));
            }
        }
        dfs(1, 0);
        for (int i = 0; i < rooms - 1; i++) {
            for (int u = 1; u < rooms + 1; u++) {
                if (cc[u] == 0 && dist[u] != -1) {
                    for (int j = 0; j < (int) adjList[u].size(); j++) {
                        ii v = adjList[u][j];
                        dist[v.first] = max(dist[v.first], dist[u] + energies[v.first]);
                    }
                }
            }
        }
        for (int u = 1; u < rooms - 1; u++) {
            bool didDfs = false;
            if (cc[u] == 0 && dist[u] != -1) {
                
                if (visited[rooms]) {

                }
                for (int j = 0; j < (int) adjList[u].size(); j++) {
                    ii v = adjList[u][j];
                    if (dist[v.first] < dist[u] + energies[v.first]) {
                        if (!didDfs) {
                            memset(visited, 0, sizeof visited);
                            dfs(u, 0);
                            didDfs = 1;
                        }
                        if (visited[rooms]) {
                            dist[rooms] = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (cc[rooms] != 0) {
            printf("hopeless\n");
        } else {
            printf("%s\n", dist[rooms] > 0 ? "winnable" : "hopeless");
        }
    }
}
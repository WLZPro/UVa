#include <cstring>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <queue>
#define INF 1000000000
using namespace std;

int res[203][203], s = 100, f;

int resBak[203][203];

vector<int> AdjList[203], p;
vector<pair<int, int> > coords;

void augment(int v, int minEdge) {
    if (v == s) {
        f = minEdge; 
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        memset(res, 0, sizeof res);
        coords.clear();
        for (int i = 0; i < 203; i++) {
            AdjList[i].clear();
        }
        int V;
        double D;
        scanf("%d %lf", &V, &D);
        D *= D;
        
        int totalPenguins = 0;
        for (int i = 0; i < V; i++) {
            int x, y, penguins, capacity;
            scanf("%d %d %d %d", &x, &y, &penguins, &capacity);
            totalPenguins += penguins;
            coords.push_back(make_pair(x, y));
            res[i][i + 101] = capacity;
            AdjList[i].push_back(i + 101);
            AdjList[i + 101].push_back(i);

            if (penguins > 0) {
                res[s][i] = penguins;
                AdjList[s].push_back(i);
                //
                AdjList[i].push_back(s);
                //
            }
        }
        for (int i = 0; i < V; i++) {
            for (int j = i+1; j < V; j++) {
                if (j != i) {
                    int x1 = coords[i].first, y1 = coords[i].second, x2 = coords[j].first, y2 = coords[j].second;
                    int sqauredDist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                    if ((double) sqauredDist <= D) {
                        AdjList[i + 101].push_back(j);
                        AdjList[j].push_back(i + 101);

                        AdjList[j + 101].push_back(i);
                        AdjList[i].push_back(j + 101);

                        res[i + 101][j] = INF;
                        res[j + 101][i] = INF;

                    }
                }
            }
        }
        bool possible = 0;
        memcpy(resBak,res,sizeof res);
        for (int t = 0; t < V; t++) {
            int mf = 0;
            memcpy(res,resBak,sizeof resBak);
            while (1) {
                f = 0;
                bitset<203> vis;
                vis[s] = true;
                queue<int> q; q.push(s);
                p.assign(203, -1);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    if (u == t) break;
                    for (int j = 0; j < (int) AdjList[u].size(); j++) {
                        int v = AdjList[u][j];
                        if (res[u][v] > 0 && !vis[v]) {
                            vis[v] = true;
                            q.push(v);
                            p[v] = u;
                        }
                    }
                }
                augment(t, INF);
                if (f == 0) break;
                mf += f;
            }
            if (mf == totalPenguins) {
                if (possible) {
                    printf(" %d", t);
                } else {
                    printf("%d", t);
                    possible = 1;
                }
            }
        }
        if (!possible) {
            printf("-1");
        }
        printf("\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000


int x, y, P;

const int s = 1800, t = 1801;

char grid[32][32];

vector<vector<int> > AdjList(2000);

int res[2000][2000];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int mf, f;

vector<int> p;

int idx(int i, int j) {
    return i * 30 + j;
}

void augment(int u, int minEdge) {
    if (u == t) {
        //printf("t\n");
    } else if (u != s) {
        if (u < 900) {
            //printf("%d,%d\n", u / 30, u % 30);
        }
    }
    if (u == s) {
        f = minEdge;
        //printf("s\n");
        return;
    } else if (p[u] != -1) {
        augment(p[u], min(minEdge, res[p[u]][u]));
        res[p[u]][u] -= f;
        //printf("%d <-% d, w = %d\n", u, p[u], res[p[u]][u]);
        res[u][p[u]] += f;
    }
}

int main() {
    while (scanf("%d %d %d", &x, &y, &P) == 3) {
        memset(grid, 0, sizeof grid);
        memset(res, 0, sizeof res);
        fgets(grid[31], 32, stdin);
        for (int i = 0; i < x; i++) {
            fgets(grid[i], 32, stdin);
            grid[i][y] = 0;
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] != '~') {
                    AdjList[idx(i, j)].push_back(900 + idx(i, j));
                    AdjList[900 + idx(i, j)].push_back(idx(i, j));
                    if (grid[i][j] == '*') {
                        AdjList[s].push_back(idx(i, j));
                        AdjList[idx(i, j)].push_back(s);
                        res[s][idx(i, j)] = INF;
                        //res[idx(i, j)][s] = INF;
                        res[idx(i, j)][900 + idx(i, j)] = 1;
                        //res[900 + idx(i, j)][idx(i, j)] = 1;
                    } else if (grid[i][j] == '.') {
                        res[idx(i, j)][900 + idx(i, j)] = 1;
                        //res[900 + idx(i, j)][idx(i, j)] = 1;
                    } else if (grid[i][j] == '@') {
                        res[idx(i, j)][900 + idx(i, j)] = INF;
                        //res[900 + idx(i, j)][idx(i, j)] = INF;
                    } else if (grid[i][j] == '#') {
                        res[idx(i, j)][900 + idx(i, j)] = INF;
                        //res[900 + idx(i, j)][idx(i, j)] = P;
                        AdjList[900 + idx(i, j)].push_back(t);
                        AdjList[t].push_back(900 + idx(i, j));
                        res[900 + idx(i, j)][t] = P;
                        //res[t][900 + idx(i, j)] = INF;
                    }
                    for (int k = 0; k < 4; k++) {
                        if (i + dy[k] < 0 || i + dy[k] >= x || j + dx[k] < 0 || j + dx[k] >= y) continue;
                        if (grid[i + dy[k]][j + dx[k]] == '~') continue;
                        AdjList[900 + idx(i, j)].push_back(idx(i + dy[k], j + dx[k]));
                        AdjList[idx(i + dy[k], j + dx[k])].push_back(900 + idx(i, j));
                        res[900 + idx(i, j)][idx(i + dy[k], j + dx[k])] = INF;
                        //res[idx(i + dy[k], j + dx[k])][900 + idx(i, j)] = INF;
                    }
                }
            }
        }
        /*for (int i = 0; i < 2000; i++) {
            if (AdjList[i].size() > 0) {
                printf("%d: ", i);
                for (int j = 0; j < (int) AdjList[i].size(); j++) {
                    printf("(%d, %d) ", AdjList[i][j], res[i][AdjList[i][j]]);
                }   
                printf("\n");
            }
        }*/
        mf = 0;
        while (1) {
            f = 0;
            p.assign(2000, -1);
            queue<int> q;
            q.push(s);
            bitset<2000> vis;
            vis[s] = 1;
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
        printf("%d\n", mf);
    }
    return 0;
}
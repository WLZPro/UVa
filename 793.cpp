#include <bits/stdc++.h>
using namespace std;

vector<int> p, sz;

int findSet(int node) {
    return p[node] == node ? node : p[node] = findSet(p[node]);
}

bool sameSet(int u, int v) {
    return findSet(u) == findSet(v);
}

void connect(int u, int v) {
    int x = findSet(u);
    int y = findSet(v);
    if (sz[x] > sz[y]) p[y] = x;
    else {
        p[x] = y;
        if (sz[x] == sz[y]) sz[y]++;
    }
}

int main() {
    char line[1000];
    fgets(line ,sizeof line, stdin);
    int TC;
    sscanf(line, "%d", &TC);
    while (TC--) {
        int n;
        fgets(line, sizeof line, stdin);
        sscanf(line, "%d", &n);
        n++;
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
        sz.assign(n, 1);
        char c;
        int x, y, suc = 0, fail = 0;
        
        while (fgets(line, sizeof line, stdin) != NULL && line[0] != '\n') {
            if (sscanf(line, "%c %d %d", &c, &x, &y) == 3) {
                if (c == 'c') {
                    connect(x, y);
                } else {
                    if (sameSet(x, y)) suc++;
                    else fail++;
                }
            }
        }
        printf("%d,%d\n", suc, fail);
        if (TC) printf("\n");
    }
    return 0;
}
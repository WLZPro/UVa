#include <bits/stdc++.h>
using namespace std;

int n, m;

map<string, int> names;
string tNames[30];
vector<vector<int> > AdjList, tAdjList;

bitset<30> vis;

void dfs(int u, vector<vector<int> > neigh, vector<int> *st) {
    vis[u] = 1;
    for (int j = 0; j < (int) neigh[u].size(); j++) {
        int v = neigh[u][j];
        if (!vis[v]) {
            dfs(v, neigh, st);
        }
    }
    st->push_back(u);
}

int main() {
    int caseNow = 1;
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> m, n || m) {
        if (caseNow > 1) cout << "\n";
        int cnt = 0;
        AdjList = vector<vector<int> >(30);
        tAdjList = vector<vector<int> >(30);
        names.clear();
        for (int i = 0; i < m; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (names.find(s1) == names.end()) {
                tNames[cnt] = s1;
                names[s1] = cnt++;
            }
            if (names.find(s2) == names.end()) {
                tNames[cnt] = s2;
                names[s2] = cnt++;
            }
            AdjList[names[s1]].push_back(names[s2]);
            tAdjList[names[s2]].push_back(names[s1]);
        }
        vector<int> topoSort;
        vis.reset();
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, AdjList, &topoSort);
            }
        }
        vis.reset();
        cout << "Calling circles for data set " << caseNow++ << ":\n";
        for (int i = n - 1; i >= 0; i--) {
            if (!vis[topoSort[i]]) {
                vector<int> scc;
                dfs(topoSort[i], tAdjList, &scc);
                for (int j = 0; j < (int) scc.size(); j++) {
                    if (j) cout << ", ";
                    cout << tNames[scc[j]];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
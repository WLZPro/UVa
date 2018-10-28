#include <bits/stdc++.h>
using namespace std;  

int t;
vector< vector<int> > adj;
vector< vector<int> > reach;
vector<int> cur(100);
vector<int> was;
int cnt;
int mx;

void dfs(int u, int d) {
  if (u == t) {
    cnt++;
    for (int i = 0; i < d; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << cur[i];
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i <= mx; i++) {
    if (was[i] || !adj[u][i] || !reach[i][t]) {
      continue;
    }
    was[i] = 1;
    cur[d] = i;
    dfs(i, d + 1);
    was[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq = 1;
  while (cin >> t) {
    adj.assign(25, vector<int>(25, 0));
    reach.assign(25, vector<int>(25, 0));
    int u, v;
    mx = 0;
    while (cin >> u >> v, u != 0 || v != 0) {
      mx = max(mx, max(u, v));
      adj[u][v] = adj[v][u] = 1;
      reach[u][v] = reach[v][u] = 1;
    }
    for (int k = 1; k <= mx; k++) {
      for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= mx; j++) {
          if (reach[i][k] && reach[k][j]) {
            reach[i][j] = 1;
          }
        }
      }
    }
    cnt = 0;
    cur[0] = 1;
    was.assign(mx + 1, 0);
    was[1] = 1;
    cout << "CASE " << qq++ << ":\n";
    dfs(1, 1);
    cout << "There are " << cnt << " routes from the firestation to streetcorner " << t << ".\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector< vector< pair<int, int> > > g(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    vector<int> dist(n + 1, INF);
    dist[n] = 0;
    queue<int> que;
    que.push(n);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (auto& v : g[u]) {
        if (dist[v.first] == INF) {
          dist[v.first] = dist[u] + 1;
          que.push(v.first);
        }
      }
    }
    vector<int> best(n + 1, INF);
    vector<int> ans(n + 1, INF);
    vector<int> was(n + 1, 0);
    que.push(1);
    was[1] = 1;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      if (best[u] != ans[dist[u]]) {
        continue;
      }
      for (auto& v : g[u]) {
        if (dist[v.first] == dist[u] - 1) {
          best[v.first] = min(best[v.first], v.second);
          ans[dist[v.first]] = min(ans[dist[v.first]], v.second);
          if (!was[v.first]) {
            was[v.first] = 1;
            que.push(v.first);
          }
        }
      }
    }
    cout << dist[1] << '\n';
    for (int i = dist[1] - 1; i >= 0; i--) {
      if (i < dist[1] - 1) {
        cout << ' ';
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

const vector<int> dx = { 1, -1, 0, 0 };
const vector<int> dy = { 0, 0, 1, -1 };

const int INF = 0x3f3f3f3f;

vector< vector<int> > g;
vector<int> was;
vector<int> topoSort;

void dfs(int u) {
  was[u] = 1;
  for (auto& v : g[u]) {
    if (!was[v]) {
      dfs(v);
    }
  }
  topoSort.push_back(u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string name;
    int r, c;
    cin >> name >> r >> c;
    vector< vector<int> > a(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> a[i][j];
      }
    }
    g.assign(r * c, vector<int>());
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        for (int k = 0; k < 4; k++) {
          int nr = i + dx[k];
          int nc = j + dy[k];
          if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
            continue;
          }
          if (a[nr][nc] < a[i][j]) {
            g[nr * c + nc].push_back(i * c + j);
          }
        }
      }
    }
    was.assign(r * c, 0);
    topoSort.clear();
    for (int i = 0; i < r * c; i++) {
      if (!was[i]) {
        dfs(i);
      }
    }
    vector<int> dist(r * c, 1);
    reverse(topoSort.begin(), topoSort.end());
    for (auto& u : topoSort) {
      for (auto& v : g[u]) {
        dist[v] = max(dist[v], dist[u] + 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < r * c; i++) {
      ans = max(ans, dist[i]);
    }
    cout << name << ": " << ans << '\n';
  }
  return 0;
}

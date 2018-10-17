#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;
vector<int> was;

int odd, cnt;

void dfs(int u) {
  was[u] = 1;
  odd += (int) g[u].size() % 2;
  cnt += (int) g[u].size();
  for (auto& v : g[u]) {
    if (!was[v]) {
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int v, e, t, qq = 1;
  while (cin >> v >> e >> t, v != 0 || e != 0 || t != 0) {
    g.assign(v + 1, {});
    for (int i = 0; i < e; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    was.assign(v + 1, 0);
    int ans = 0;
    int pos = 0;
    for (int i = 1; i <= v; i++) {
      if (!was[i]) {
        cnt = odd = 0;
        dfs(i);
        if (cnt > 0) {
          pos = 1;
          ans += cnt / 2 + max(0, odd / 2 - 1) + 1;
        }
      }
    }
    ans -= pos;
    ans *= t;
    cout << "Case " << qq++ << ": " << ans << '\n'; 
  }
  return 0;
}

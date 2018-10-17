#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int np, qq = 1;
  while (cin >> np, np != 0) {
    vector<int> cnt(np + 1);
    for (int i = 1; i <= np; i++) {
      cin >> cnt[i];
    }
    int nt;
    cin >> nt;
    vector< map<int, int> > in(nt + 1);
    vector< vector<int> > out(nt + 1);
    vector< vector<int> > conn(np + 1);
    for (int i = 1; i <= nt; i++) {
      int x;
      while (cin >> x, x != 0) {
        if (x < 0) {
          in[i][-x]++;
          conn[-x].push_back(i);
        } else {
          out[i].push_back(x);
        }
      }
    }
    vector<int> in_que(nt + 1);
    queue<int> que;
    for (int i = 1; i <= nt; i++) {
      int enabled = 1;
      for (auto& x : in[i]) {
        if (cnt[x.first] < x.second) {
          enabled = 0;
          break;
        }
      }
      if (enabled) {
        in_que[i] = 1;
        que.push(i);
      }
    }
    int nf;
    cin >> nf;
    cout << "Case " << qq++ << ": ";
    int dead = 0;
    for (int t = 0; t < nf; t++) {
      if (que.empty()) {
        cout << "dead after " << t << " transitions\n";
        dead = 1;
        break;
      }
      int u = que.front();
      que.pop();
      in_que[u] = 0;
      for (auto& x : in[u]) {
        cnt[x.first] -= x.second;
      } 
      for (auto& x : out[u]) {
        cnt[x]++;
      }
      for (auto& x : out[u]) {
        for (auto& y : conn[x]) {
          if (in_que[y]) {
            continue;
          }
          int enabled = 1;
          for (auto& z : in[y]) {
            if (cnt[z.first] < z.second) {
              enabled = 0;
              break;
            }
          }
          if (enabled) {
            in_que[y] = 1;
            que.push(y);
          }
        }
      }
      int enabled = 1;
      for (auto& x : in[u]) {
        if (cnt[x.first] < x.second) {
          enabled = 0;
          break;
        }
      }
      if (enabled) {
        in_que[u] = 1;
        que.push(u);
      }
    }
    if (!dead) {
      cout << "still live after " << nf << " transitions\n";
    }
    cout << "Places with tokens:";
    for (int i = 1; i <= np; i++) {
      if (cnt[i] > 0) {
        cout << ' ' << i << " (" << cnt[i] << ")";
      }
    }
    cout << '\n' << '\n';
  }
  return 0;
}

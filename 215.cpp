#include <bits/stdc++.h>
using namespace std;  

int r, c;
vector<int> val;
vector< vector< pair<int, int> > > g;
vector<int> was;
vector<string> str;
vector<int> eval;

void dfs(int u) {
  was[u] = 1;
  for (auto& v : g[u]) {
    if (!was[v.first]) {
      dfs(v.first);
    }
    if (!eval[v.first]) {
      return;
    }
    val[u] += val[v.first] * v.second;
  }
  eval[u] = 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> r >> c, r != 0 || c != 0) {
    val.assign(r * c, 0);
    g.assign(r * c, {});
    str.assign(r * c, "");    
    for (int i = 0; i < r * c; i++) {
      string s;
      cin >> s;
      str[i] = s;
      s += '+';
      int prevsign = +1;
      if (s[0] == '-') {
        prevsign = -1;
      } else {
        s = '+' + s;
      }
      int prev = 1;
      for (int j = 1; j < (int) s.size(); j++) {
        if (s[j] == '-' || s[j] == '+') {
          if (isdigit(s[prev])) {
            val[i] += stoi(s.substr(prev, j - prev)) * prevsign;
          } else {
            g[i].emplace_back((s[j - 2] - 'A') * c + s[j - 1] - '0', prevsign);
          }
          prevsign = +1;
          if (s[j] == '-') {
            prevsign = -1;
          }
          prev = j + 1;
        }
      }
    }
    eval.assign(r * c, 0);
    was.assign(r * c, 0);
    for (int i = 0; i < r * c; i++) {
      if (!was[i]) {
        dfs(i);
      }
    }
    int cyc = 0;
    for (int i = 0; i < r * c; i++) {
      if (!eval[i]) {
        cyc = 1;
        cout << (char) (i / c + 'A') << i % c << ": " << str[i] << '\n';
      }
    }
    if (cyc) {
      cout << '\n';
      continue;
    }
    cout << ' ';
    for (int i = 0; i < c; i++) {
      cout << setw(6) << i;
    }
    cout << '\n';
    for (int i = 0; i < r; i++) {
      cout << (char) (i + 'A');
      for (int j = 0; j < c; j++) {
        cout << setw(6) << val[i * c + j];
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}

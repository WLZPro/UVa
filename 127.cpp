#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector< vector<string> > v(52, vector<string>(1));
  while (cin >> v[0][0], v[0][0] != "#") {
    for (int i = 1; i < 52; i++) {
      cin >> v[i][0];
    }
    int pos;
    do {
      pos = 0;
      for (int i = 1; i < (int) v.size(); i++) {
        if (v[i].empty()) {
          continue;
        }
        if (i >= 3 && !v[i - 3].empty()) {
          if (v[i].back()[0] == v[i - 3].back()[0] || v[i].back()[1] == v[i - 3].back()[1]) {
            v[i - 3].push_back(v[i].back());
            v[i].pop_back();
            pos = 1;
            break;
          }
        }
        if (v[i - 1].empty()) {
          continue;
        }
        if (v[i].back()[0] == v[i - 1].back()[0] || v[i].back()[1] == v[i - 1].back()[1]) {
          v[i - 1].push_back(v[i].back());
          v[i].pop_back();
          pos = 1;
          break;
        }
      }
      for (int i = 0; i < (int) v.size(); i++) {
        if (v[i].empty()) {
          v.erase(v.begin() + i);
        }
      }
    } while (pos);
    vector<int> ans;
    for (int i = 0; i < (int) v.size(); i++) {
      /*
      for (auto& s : v[i]) {
        cout << s << ' ';
      }
      cout << '\n';
      */
      ans.push_back((int) v[i].size());
    }
    cout << (int) ans.size() << " pile";
    if ((int) ans.size() > 1) {
      cout << 's';
    }
    cout << " remaining:";
    for (auto& x : ans) {
      cout << ' ' << x;
    }
    cout << '\n';
    v.assign(52, vector<string>(1));
  }
  return 0;
}

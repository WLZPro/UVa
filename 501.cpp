#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;
  while (k--) {
    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    vector<int> cur;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      int u;
      cin >> u;
      while (idx < u) {
        auto it = lower_bound(cur.begin(), cur.end(), a[idx]);
        cur.insert(it, a[idx]);
        idx++;
      }
      cout << cur[i] << endl;
    }
    if (k > 0) {
      cout << endl;
    }
  }
  return 0;
}

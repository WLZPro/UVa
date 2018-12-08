#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, qq = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
      p.push_back(p[i]);
      q.push_back(q[i]);
    }
    p.push_back(p[0]);
    q.push_back(q[0]);
    int i = 0;
    int found = 0;
    cout << "Case " << qq++ << ": ";
    while (i < n) {
      int cur = 0;
      int pos = -1;
      for (int j = i; j < i + n; j++) {
        cur += p[j];
        cur -= q[j];
        if (cur < 0) {
          pos = j;
          break;
        }
      }
      if (pos == -1) {
        found = 1;
        cout << "Possible from station " << i + 1 << '\n';
        break;
      }
      i = pos + 1;
    }
    if (!found) {
      cout << "Not possible\n";
    }
  }
  return 0;
}

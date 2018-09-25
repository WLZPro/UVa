#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, qq = 1;
  while (cin >> n, n != 0) {
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      x[i] = s[1] - '1';
    }
    string out;
    cin >> out;
    int q;
    cin >> q;
    cout << "S-Tree #" << qq++ << ":\n";
    while (q--) {
      string s;
      cin >> s;
      int pos = 0;
      for (int i = 0; i < n; i++) {
        if (s[x[i]] == '1') {
          pos += (1 << (n - i - 1));
        }
      }
      cout << out[pos];
    }
    cout << "\n\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

map<long long, int> mp;
int sz;

void read(int i, int j, const string& s, int d) {
  if (s[i] == '[') {
    int p = 0;
    int pos = 0;
    for (int k = i + 1; ;k++) {
      if (s[k] == '[') {
        p++;
      } else if (s[k] == ']') {
        p--;
      }
      if (p == 0 && s[k] == ',') {
        pos = k;
        break;
      }
    }
    read(i + 1, pos - 1, s, d + 1);
    read(pos + 1, j - 1, s, d + 1);
  } else {
    sz++;
    long long w = stoi(s.substr(i, j - i + 1));
    mp[w << d]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  string s;
  cin >> t;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    mp.clear();
    sz = 0;
    read(0, (int) s.length() - 1, s, 0);
    int mx = 0;
    for (auto& x : mp) {
      mx = max(mx, x.second);
    }
    cout << sz - mx << '\n';
  }
  return 0;
}

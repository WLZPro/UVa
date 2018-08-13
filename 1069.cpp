#include <bits/stdc++.h>

using namespace std;

long long d;
vector<long long> p;

template<typename T>
T modpow(T b, T p) {
  if (!p) {
    return (T) 1;
  }
  T ans = modpow(b, p >> 1);
  ans = ans * ans % d;
  if (p % 2 == 1) {
    ans = ans * b % d;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int qq = 1;
  while (cin >> s, s != ".") {
    p.assign(101, 0ll);
    stringstream splitter(s);
    string seg, t;
    getline(splitter, seg, '/');
    t = seg;
    getline(splitter, seg, '/');
    d = (long long) stoi(seg);
    s = t.substr(1, (int) t.length() - 2);
    for (int i = 0; i < (int) s.length(); i++) {
      if (i > 0 && s[i] == '-') {
        s.insert(s.begin() + i, '+');
        i++;
      }
    }
    vector<string> v;
    splitter = stringstream(s);
    while (getline(splitter, seg, '+')) {
      v.push_back(seg);
    }
    p.clear();
    for (auto& x : v) {
      int neg = 1;
      if (x[0] == '-') {
        neg = -1;
        x = x.substr(1, (int) x.length() - 1);
      }
      int pos, val;
      string c, e;
      stringstream rd(x);
      getline(rd, c, '^');
      if (getline(rd, e, '^')) { // e > 1
        pos = stoi(e);
      } else { // e = 0 or e = 1
        if (c[(int) c.length() - 1] == 'n') {
          pos = 1;
        } else {
          pos = 0;
        }
      }
      if (c[(int) c.length() - 1] == 'n') {
        c = c.substr(0, (int) c.size() - 1);
      }
      if (c == "") {
        val = 1;
      } else {
        val = stoi(c);
      }
      p[pos] = (long long) (val * neg);
    }
    int pos = 1;
    for (int i = 0; i <= 100; i++) {
      long long val = 0ll;
      for (int j = 0; j <= 100; j++) {
        val += p[j] * modpow((long long) i, (long long) j);
        if (val < 0) {
          int tmp = (abs(val) + d - 1) / d;
          val += (long long) tmp * d;
        }
        val %= d;
      }
      if (val != 0ll) {
        pos = 0;
        break;
      }
    }
    cout << "Case " << qq++ << ": ";
    if (pos) {
      cout << "Always an integer";
    } else {
      cout << "Not always an integer";
    }
    cout << endl;
  }
  return 0;
}

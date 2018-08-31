#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class fenwick {
  public:
    vector<T> fenw;
    int n;

    fenwick(int _n) : n(_n) {
      fenw.resize(n);
    }

    void modify(int x, T v) {
      while (x < n) {
        fenw[x] += v;
        x |= (x + 1);
      }
    }

    T get(int x) {
      T v{};
      while (x >= 0) {
        v += fenw[x];
        x = (x & (x + 1)) - 1;
      }
      return v;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, qq = 1;
  while (cin >> n, n != 0) {
    vector<int> a(n);
    fenwick<int> fenw((int) 1e4 + 1);
    int mi = (int) 1e9;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      fenw.modify(a[i], +1);
      mi = min(mi, a[i]);
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = fenw.get(a[i]) - 1;
    }
    vector<int> was(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (was[i]) {
        continue;
      }
      int p = i;
      int mn = (int) 1e9;
      int sum = 0;
      int len = 0;
      while (!was[p]) {
        was[p] = 1;
        sum += a[p];
        mn = min(mn, a[p]);
        p = v[p];
        len++;
      }
      if (len == 1) {
        continue;
      }
      len--;
      ans += (sum - mn) + mn * len;
      if ((mi + mn) * 2 < len * (mn - mi)) {
        ans -= len * (mn - mi) - (mi + mn) * 2;
      }
    }
    cout << "Case " << qq++ << ": " << ans << endl << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
  private:
    int n;
    vector<int> fenw;
  public:
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

    T get(int a, int b) {
      if (a > b) {
        swap(a, b);
      }
      T v = get(b);
      if (a > 0) {
        v -= get(a - 1);
      }
      return v;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    fenwick<int> fenw(n + m + 2);
    int sz = n + m + 2;
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++) {
      fenw.modify(i, +1);
      ind[i] = n - i + 1;
    }
    int pos = n + 1;
    while (m--) {
      int x;
      cin >> x;
      cout << fenw.get(ind[x] + 1, sz - 1);
      fenw.modify(ind[x], -1);
      ind[x] = pos++;
      fenw.modify(ind[x], +1);
      if (m > 0) {
        cout << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}

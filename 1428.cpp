#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class fenwick {
  private:
    vector<int> fenw;
    int n;
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

    T get(int x, int y) {
      if (x > y) {
        swap(x, y);
      }
      T v = get(y);
      if (x > 0) {
        v -= get(x - 1);
      }
      return v;
    }

    void reset() {
      fenw.assign(n, T{});
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<long long> c(n + 1);
    vector<long long> d(n + 1);
    fenwick<int> fenw((int) 1e5 + 5);
    for (int i = 1; i <= n; i++) {
      c[i] = (long long) fenw.get(a[i] - 1);
      fenw.modify(a[i], +1);
    }
    fenw.reset();
    for (int i = n; i >= 1; i--) {
      d[i] = (long long) fenw.get(a[i] - 1);
      fenw.modify(a[i], +1);
    }
    #ifdef DEBUG
    for (auto& x : c) {
      cout << x << " ";
    }
    cout << endl;
    for (auto& x : d) {
      cout << x << ' ';
    }
    cout << endl;
    #endif
    long long ans = 0ll;
    for (int i = 1; i <= n; i++) {
      ans += c[i] * (long long) (n - i - d[i]) + d[i] * (long long) (i - c[i] - 1);
    }
    cout << ans << endl;
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int x;
long long n, r;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq = 1;
  while (cin >> x >> n >> r, x != 0 && n != 0 && r != 0) {
    set<long long> ans;
    long long tot = 0ll;
    for (long long p = 1ll; p * p <= n; p++) {
      if (n % p != 0) {
        continue;
      }
      long long q = n / p;
      long long m1 = -r / q - 1ll;
      long long start = m1;
      //cout << "starting at " << m1 << endl;
      while (true) {
        long long y = m1 * q + r;
        if (y < n && y >= 1 && (y + r) % p == 0) {
          ans.insert(y);
        }
        y = m1 * q - r;
        if (y >= n) {
          tot += m1 - start + 1;
          //cout << "ending at " << m1 << endl;
          break;
        }
        if (y < n && y >= 1 && (y - r) % p == 0) {
          ans.insert(y);
        }
        m1++;
      }
    }
    //cout << "total checks " << tot << endl;
    cout << "Case " << qq++ << ":";
    for (auto& x : ans) {
      cout << " " << x;
    }
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 100000007;

pair<long long, long long> solveEq(long long lhs, long long rhs) {

  long long dm = 8 * rhs + lhs;
  long long dn = 9 * rhs + 2 * lhs;

  if (dm % 7 > 0 || dn % 7 > 0) {
    return {-1ll, -1ll};
  }

  long long m = dm / 7;
  long long n = dn / 7;

  if (n <= 0 || m <= 0 || m > n) {
    return {-1ll, -1ll};
  }
  return {n, m};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long s;
  while (cin >> s, s != 0ll) {
    set<long long, greater<long long> > ans;
    for (long long lhs = 1ll; lhs * lhs <= s; lhs++) {
      if (s % lhs == 0) {
        long long rhs = s / lhs;
        /*
         * lhs = (-9m + 8n)
         * rhs = ( 2m -  n)
         * or
         * lhs = ( 2m -  n)
         * rhs = (-9m + 8n)
         */
        auto p = solveEq(lhs, rhs);
        if (p.first != -1ll) {
          long long k = 2ll * p.first - 3ll * p.second;
          if (k > 0) {
            ans.insert(k);
          }
        }
        p = solveEq(rhs, lhs);
        if (p.first != -1ll) {
          long long k = 2ll * p.first - 3ll * p.second;
          if (k > 0) {
            ans.insert(k);
          }
        }
      }
    }
    if (ans.empty()) {
      cout << "No Solution Possible" << endl;
    } else {
      for (auto& x : ans) {
        cout << "Possible Missing Soldiers = " << ((x % MOD) * (x % MOD) * 2ll) % MOD << endl;
      }
    }
    cout << endl;
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<long long> ab;
    for (auto& x : a) {
      for (auto& y : b) {
        ab.push_back(x + y);
      }
    }
    sort(ab.begin(), ab.end());
    long long ans = 0ll;
    for (auto& x : c) {
      for (auto& y : d) {
        ans += (long long)(upper_bound(ab.begin(), ab.end(), -x - y) - lower_bound(ab.begin(), ab.end(), -x - y));
      }
    }
    cout << ans << '\n';
    if (t > 0) {
      cout << '\n';
    }
  }
  return 0;
}

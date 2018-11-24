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
  int n;
  while (cin >> n, n != 0) {
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0ll;
    vector<long long> b(n, 0ll);
    for (int i = 0; i < n - 1; i++) {
      b[i + 1] -= a[i] - b[i];
      ans += (long long) abs(a[i] - b[i]);
      b[i] = a[i];
    }
    cout << ans << '\n';
  }
  return 0;
}

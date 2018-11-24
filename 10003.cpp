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

int l;
int n;
vector<int> a;
vector< vector<int> > dp;
const int INF = 0x3f3f3f3f;

int solve(int i, int j) {
  if (i + 1 == j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int ans = INF;
  for (int k = i + 1; k < j; k++) {
    ans = min(ans, solve(i, k) + solve(k, j) + (a[j] - a[i]));
  }
  return dp[i][j] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> l, l != 0) {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a.push_back(l);
    dp.assign(n + 2, vector<int>(n + 2, -1));
    cout << "The minimum cutting is " << solve(0, n + 1) << ".\n";
  }
  return 0;
}

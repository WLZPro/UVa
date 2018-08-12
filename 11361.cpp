#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <cmath>

using namespace std;

const int MAX_LOG = 11;

vector< vector< vector<int> > > dp;
vector<int> pw;

void precalc(int k) {
  dp.assign(MAX_LOG + 1, vector< vector<int> >(min(k, 101), vector<int>(k)));
  dp[0][0][0] = 1;
  pw.assign(12, 1);
  for (int i = 1; i < 12; i++) {
    pw[i] = (pw[i - 1] * 10) % k;
  }
  for (int i = 0; i < MAX_LOG; i++) {
    for (int m1 = 0; m1 < min(k, 101); m1++) {
      for (int m2 = 0; m2 < k; m2++) {
        if (dp[i][m1][m2] == 0) {
          continue;
        }
        for (int x = 0; x < 10; x++) {
          dp[i + 1][(m1 + x) % k][(m2 + x * pw[i]) % k] += dp[i][m1][m2];
        }
      }
    }
  }
}

int calc(int a, int k) {
  int ans = 0;
  vector<int> digits;
  while (a > 0) {
    digits.push_back(a % 10);
    a /= 10;
  }
  int len = (int) digits.size();
  int prev = 0;
  int prevnum = 0;
  for (int t = len - 1; t >= 0; t--) {
    for (int j = 0; j < digits[t]; j++) {
      int m1 = (k - ((prev + j) % k)) % k;
      int m2 = (k - ((prevnum * pw[t + 1] + j * pw[t])) % k) % k;
      if (m1 >= (int) dp[0].size() || m2 >= (int) dp[0][0].size()) {
        continue;
      }
      ans += dp[t][m1][m2];
    }
    prev += digits[t];
    prevnum = prevnum * 10 + digits[t];
  }
  if (prev % k == 0 && prevnum % k == 0) {
    ans++;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, k;
    cin >> a >> b >> k;
    precalc(k);
    cout << calc(b, k) - calc(a - 1, k) << endl;
  }
  return 0;
}

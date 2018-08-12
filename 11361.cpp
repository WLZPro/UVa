#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int calc(int a, int k) {
  if (a == 0) {
    return 1;
  }
  vector<int> ad;
  while (a > 0) {
    ad.push_back(a % 10);
    a /= 10;
  }
  //reverse(ad.begin(), ad.end());
  int len = (int) ad.size();
  vector< vector< vector<int> > > dp(len + 1, vector< vector<int> >(min(k, 101), vector<int>(k, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < len; i++) {
    for (int m1 = 0; m1 < min(k, 101); m1++) {
      for (int m2 = 0; m2 < k; m2++) {
        if (dp[i][m1][m2] == 0) {
          continue;
        }
        for (int x = 0; x < 10; x++) {
          dp[i + 1][(m1 + x) % k][(m2 + x * ((int)pow(10, i)%k)) % k] += dp[i][m1][m2];
        }
      }
    }
  }

  int ans = 0;
  int prev = 0;
  int prevnum = 0;
  for (int t = len - 1; t >= 0; t--) {
    for (int j = 0; j < ad[t]; j++) {
      int idx1 = (k - ((prev + j) % k)) % k;
      int idx2 = (k - ((prevnum * (int) pow(10, t + 1) + j * (int) pow(10, t)) % k)) % k;
      if ((idx1 < (int)dp[0].size()) && idx2 < (int)dp[0][0].size()) {
        ans += dp[t][(k - ((prev + j) % k)) % k][(k - ((prevnum * (int) pow(10, t + 1) + j * (int) pow(10, t)) % k)) % k];
      }
    }
    
    prev += ad[t];
    prevnum *= 10;
    prevnum += ad[t];
  }
  //cout << prevnum << endl;
  if (prevnum % k == 0 && prev % k == 0) {
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
    cout << calc(b, k) - calc(a - 1, k) << endl;
  }
  return 0;
}

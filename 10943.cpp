#include <iostream>
#include <vector>

using namespace std;

const int MOD = (int) 1e6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while (cin >> n >> k, n != 0 || k != 0) {
    vector< vector<int> > dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < k; j++) {
        if (dp[i][j] == 0) {
          continue;
        }
        for (int t = 0; i + t <= n; t++) {
          dp[i + t][j + 1] = (dp[i + t][j + 1] + dp[i][j]) % MOD;
        }  
      }
    }
    cout << dp[n][k] << endl;
  }
  return 0;
}

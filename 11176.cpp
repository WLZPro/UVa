#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  double p;
  while (cin >> n >> p, n != 0) {
    vector< vector<double> > dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        if (dp[i][j] < EPS) {
          continue;
        }
        dp[i + 1][j] += dp[i][j] * (1.0 - p);
        for (int t = 1; t < n - i; t++) {
          if (t < j) {
            dp[i + t + 1][j] += dp[i][j] * pow(p, (double) t) * (1.0 - p);
          } else {
            dp[i + t + 1][t] += dp[i][j] * pow(p, (double) t) * (1.0 - p);
          }
        }
        if (n - i < j) {
          dp[n][j] += dp[i][j] * pow(p, (double) (n - i));
        } else {
          dp[n][n - i] += dp[i][j] * pow(p, (double) (n - i));
        }
      }
    }
    double ans = 0.0;
    for (int i = 0; i <= n; i++) {
      ans += (double) i * dp[n][i];
    }
    cout << fixed << setprecision(6) << ans << endl;
  }
  return 0;
}

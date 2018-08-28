#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> g, p;
vector<long long> primes;

void gen_primes(long long sz) {
  g = p = vector<int>(sz + 1, 0);
  for (long long i = 2; i <= sz; i++) {
    if (g[i] == 0) {
      primes.push_back(i);
      for (long long j = i; j <= sz; j += i) {
        g[j]++;
      }
    }
  }
  primes.push_back((int) 1e9);
  int idx = 0;
  for (int i = 1; i <= sz; i++) {
    p[i] = p[i - 1];
    if (i >= primes[idx]) {
      p[i]++;
      idx++;
    }
  }
  primes.pop_back();
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  gen_primes((int) 1e6);
  vector<double> dp((int) 1e6 + 1);
  dp[1] = 0.0;
  for (int i = 1; i <= (int) 1e6; i++) {
    dp[i] += (double) p[i];
    if (g[i] > 0) {
      dp[i] /= (double) g[i];
    }
    for (auto& x : primes) {
      if ((long long) i * x > (long long) 1e6) {
        break;
      }
      dp[i * x] += dp[i];
    }
  }
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    cin >> n;
    cout << "Case " << qq << ": " << fixed << setprecision(10) << dp[n] << endl;
  }
  return 0;
}

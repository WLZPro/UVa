#include <iostream>

using namespace std;

const long long MOD = (int) 1e9 + 7;

long long modpow(long long b, long long p) {
  if (p == 0ll) {
    return 1ll;
  }
  long long ans = modpow(b, p >> 1);
  ans = (ans * ans) % MOD;
  if (p % 2 == 1) {
    ans = (ans * b) % MOD;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    long long n;
    cin >> n;
    cout << "Case #" << qq << ": " << (n * modpow(2ll, n - 1ll)) % MOD << endl;
  }
  return 0;
}

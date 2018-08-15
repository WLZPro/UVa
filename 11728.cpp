#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;
vector<int> isPrime((int) 1e6, 1);

void gen_primes() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i <= (int) 1e6; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= (int) 1e6; j += i) {
        isPrime[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

long long sumDiv(int x) {
  int idx = 0;
  long long ans = 1ll;
  while (primes[idx] * primes[idx] <= x) {
    int pw = 0;
    while (x % primes[idx] == 0) {
      x /= primes[idx];
      pw++;
    }
    ans *= ((long long) pow(primes[idx], pw + 1.0) - 1) / (primes[idx] - 1);
    idx++;
  }
  if (x > 1) {
    ans *= ((long long) pow(x, 2) - 1) / (x - 1);
  }
  return ans;
}

vector<int> ans(1001, -1);

void precomp() {
  gen_primes();
  for (int i = 1; i <= 1000; i++) {
    int sum = sumDiv(i);
    if (sum > 1000) {
      continue;
    }
    ans[sum] = i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s;
  int qq = 1;
  precomp();
  while (cin >> s, s != 0) {
    cout << "Case " << qq++ << ": " << ans[s] << endl;
  }
  return 0;
}

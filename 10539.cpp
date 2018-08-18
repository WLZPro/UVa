#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> isPrime((int) 1e6 + 1, 1);
vector<int> primes;

void gen_primes() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i <= (int) 1e6; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= (int) 1e6; j += i) {
        isPrime[j] = 0;
      }
    }
  }
  for (int i = 2; i <= (int) 1e6; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
}

vector<long long> powers;

void precomp() {
  gen_primes();
  for (auto& x : primes) {
    for (long long i = (long long) x * (long long) x; i <= (long long) 1e12; i *= (long long) x) {
      powers.push_back(i);
    }
  }
  sort(powers.begin(), powers.end());
  powers.erase(unique(powers.begin(), powers.end()), powers.end());
  powers.push_back((long long) 1e18);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  precomp();
  int n;
  cin >> n;
  while (n--) {
    long long l, r;
    cin >> l >> r;
    cout << upper_bound(powers.begin(), powers.end(), r) - lower_bound(powers.begin(), powers.end(), l) << endl;
  }
  return 0;
}

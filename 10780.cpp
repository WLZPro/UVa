#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;
vector<int> isPrime((int) 1e4, 1);
vector< vector<int> > factors((int) 1e4);
vector< vector<int> > fact((int) 1e4);

void gen_primes() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i < (int) 1e4; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j < (int) 1e4; j += i) {
        isPrime[j] = 0;
      }
    }
  }
  for (int i = 2; i < (int) 1e4; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
  factors[2] = {2};
  fact[2] = {2};
  for (int i = 3; i < (int) 1e4; i++) {
    factors[i] = factors[i - 1];
    int x = i;
    int idx = 0;
    while (idx < (int) primes.size() && x > 1) {
      while (x % primes[idx] == 0) {
        x /= primes[idx];
        factors[i].push_back(primes[idx]);
        fact[i].push_back(primes[idx]);
      }
      idx++;
    }
    if (x > 1) {
      factors[i].push_back(x);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  gen_primes();
  for (int qq = 1; qq <= tt; qq++) {
    int m, n;
    cin >> m >> n;
    vector<int> mfreq((int) 1e4, 0);
    vector<int> nfreq((int) 1e4, 0);
    for (auto& x : factors[n]) {
      nfreq[x]++;
    }
    for (auto& x : fact[m]) {
      mfreq[x]++;
    }
    int ans = (int) 1e9;
    for (int i = 2; i < (int) 1e4; i++) {
      if (mfreq[i] == 0) {
        continue;
      }
      ans = min(ans, nfreq[i] / mfreq[i]);
    }
    cout << "Case " << qq << ":" << endl;
    if (ans == 0) {
      cout << "Impossible to divide";
    } else {
      cout << ans;
    }
    cout << endl;
  }
  return 0;
}

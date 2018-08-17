#include <iostream>
#include <vector>

using namespace std;

vector<int> isPrime((int) 1e6 + 1, 1);
vector<long long> primes;

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
      primes.push_back((long long) i);
    }
  }  
}

int numDiv(long long x) {
  int ans = 1, idx = 0;
  while (primes[idx] * primes[idx] <= x) {
    int cnt = 1;
    while (x % primes[idx] == 0) {
      x /= primes[idx];
      cnt++;
    }
    ans *= cnt; 
    idx++;             
  }  
  if (x != 1) {
    ans *= 2;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  gen_primes();
  int n;
  cin >> n;
  while (n--) {
    long long l, u;
    cin >> l >> u;
    int ans = -1;
    int mx = 0;
    for (long long i = l; i <= u; i++) {
      int cnt = numDiv(i);
      if (cnt > mx) {
        mx = cnt;
        ans = i;
      }
    }
    cout << "Between " << l << " and " << u << ", " << ans << " has a maximum of " << mx << " divisors." << endl;
  }
  return 0;
}

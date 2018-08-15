#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
T findGcd(T a, T b) {
  if (a < b) {
    swap(a, b);
  }
  while (b > 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

long long read() {
  double tmp;
  cin >> tmp;
  return (long long) (tmp * 10.0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long x1, x2, y1, y2;
    x1 = read();
    y1 = read();
    x2 = read();
    y2 = read();
    long long gcd = findGcd(abs(x1 - x2), abs(y1 - y2));
    long long n = (x2 - x1) / gcd;
    long long m = (y2 - y1) / gcd;
    //cout << n << ' ' << m << endl;
    vector<int> v;
    for (int i = 0; i < 10; i++) {
      if ((x1 + i * n) % 10 == 0 && (y1 + i * m) % 10 == 0){
        v.emplace_back(i);
      }
    }
    long long ans = 0ll;
    while (!v.empty()) {
      int cur = v.back();
      v.pop_back();
      if (gcd - cur < 0) {
        continue;
      }
      ans += (gcd - cur) / 10 + 1;
    }
    cout << ans << endl;
  }
  return 0;
}

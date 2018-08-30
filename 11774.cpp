#include <iostream>
using namespace std;

template<typename T>
T findGcd(T a, T b) {
  if (b > a) {
    swap(a, b);
  }
  while (b > 0) {
    swap(a, b);
    b %= a;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    long long n, m;
    cin >> n >> m;
    long long gcd = findGcd(n, m);
    cout << "Case " << qq << ": " << (n + m) / gcd << endl;
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  int qq = 1;
  while (cin >> n >> r, n != 0 || r != 0) {
    vector<double> v(n);
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i < r; i++) {
      a[i] = 1;
    }
    vector<double> p(n, 0.0);
    double sum = 0.0;
    do {
      double prob = 1.0;
      for (int i = 0; i < n; i++) {
        if (a[i]) {
          prob *= v[i];
        } else {
          prob *= (1.0 - v[i]);
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i]) {
          p[i] += prob;
        }
      }
      sum += prob;
    } while (prev_permutation(a.begin(), a.end()));
    cout << "Case " << qq++ << ":" << endl; 
    for (int i = 0; i < n; i++) {
      cout << fixed << setprecision(6) << p[i] / sum << endl;
    }
  }
  return 0;
}

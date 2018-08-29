#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> v(n);
    for (int i = 0; i < 5; i++) {
      cin >> v[i];
      for (int j = 0; j < v[i]; j++) {
        a.push_back(i);
      }
    }
    vector< vector<double> > p(n, vector<double>(5));
    vector<double> g(5, 0.0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> p[i][j];
      }
    }
    do {
      double prob = 1.0;
      for (int i = 0; i < n; i++) {
        prob *= p[i][a[i]];
      }
      g[a[0]] += prob;
    } while (next_permutation(a.begin(), a.end()));
    double ans = -(1.0 / 0.0);
    int best;
    double sum = 0.0;
    for (int i = 0; i < 5; i++) {
      sum += g[i];
    }
    for (int i = 0; i < 5; i++) {
      if (v[i] > 0) {
        best = i;
        break;
      }
    }
    for (int i = 0; i < 5; i++) {
      if ((g[i] / sum) / v[i] > ans) {
        best = i;
        ans = (g[i] / sum) / v[i];
      }
    }
    cout << best + 1 << ' ' << fixed << setprecision(3) << ans << endl;
  }
  return 0;
}

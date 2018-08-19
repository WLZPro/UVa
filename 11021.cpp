#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int n, k, m;
    cin >> n >> k >> m;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    vector<double> v(m + 1, 0.0);
    v[1] = p[0];
    for (int i = 2; i <= m; i++) {
      for (int j = 0; j < n; j++) {
        v[i] += p[j] * pow(v[i - 1], j);
      }
    }
    cout << "Case #" << qq << ": " << fixed << setprecision(7) << pow(v[m], k) << endl;
  } 
  return 0; 
}

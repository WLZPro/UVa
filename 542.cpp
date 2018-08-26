#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int n = 16;
  vector<string> names(n);
  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }
  vector< vector<double> > win(n, vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> win[i][j];
      win[i][j] /= 100.0;
    }
  }
  vector< vector<double> > v(5, vector<double>(n, 0.0));
  for (int i = 0; i < n; i++) {
    v[0][i] = 1.0;
  }
  for (int i = 0; i < 4; i++) {
    int k = (1 << i);
    for (int j = 0; j < n / k; j += 2) {
      for (int s = j * k; s < (j + 1) * k; s++) {
        for (int t = (j + 1) * k; t < (j + 2) * k; t++) {
          v[i + 1][s] += v[i][t] * v[i][s] * win[s][t];
          v[i + 1][t] += v[i][t] * v[i][s] * win[t][s];
        }
      }
    }
  }
  #ifdef DEBUG
  cout << fixed << setprecision(2) << endl;
  for (auto& x : v) {
    for (auto& y : x) {
      cout << y << ' ';
    }
    cout << endl;
  }
  #endif
  for (int i = 0; i < n; i++) {
    cout.width(11);
    cout << left << names[i] << "p=" << fixed << setprecision(2) << v[4][i] * 100.0 << "%" << endl;
  }
  return 0;
}

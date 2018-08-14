#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int g, l;
    cin >> g >> l;
    if (l % g > 0) {
      cout << -1 << endl;
      continue;
    }
    cout << g << ' ' << l << endl;
  }
  return 0;
}

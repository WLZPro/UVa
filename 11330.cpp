#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> pos((int) 1e4 + 1);
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
      if (a[i] == a[i + 1]) {
        continue;
      }
      pos[a[i + 1]] = max(pos[a[i + 1]], pos[a[i]]);
      swap(a[i + 1], a[pos[a[i]]]);
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}

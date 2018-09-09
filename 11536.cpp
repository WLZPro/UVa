#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i < n; i++) {
      a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
    }
    int i = 0, j = 0;
    vector<int> freq(k + 1, 0);
    int in = 0;
    int ans = n + n;
    while (i < n) {
      if (a[i] <= k) {
        freq[a[i]]++;
        if (freq[a[i]] == 1) {
          in++;
        }
      }
      if (in == k) {
        ans = min(ans, i - j + 1);
      }
      while (in == k && j < i) {
        ans = min(ans, i - j + 1);
        if (a[j] <= k) {
          freq[a[j]]--;
          if (freq[a[j]] == 0) {
            in--;
          }
        }
        j++;
      }
      i++;
    }
    cout << "Case " << qq << ": ";
    if (ans == n + n) {
      cout << "sequence nai";
    } else {
      cout << ans;
    }
    cout << endl;
  }
  return 0;
}

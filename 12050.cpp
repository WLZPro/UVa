#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  while (cin >> n, n != 0) {
    int len = 1;
    while (n > 9 * (long long) pow(10, (len - 1) / 2)) {
      n -= 9 * (long long) pow(10, (len - 1) / 2);
      len++;
    }
    n--;
    vector<int> ans;
    int left = (len - 1) / 2;
    while (left > 0) {
      ans.push_back(n % 10);
      n /= 10;
      left--;
    }
    while ((int) ans.size() < (len - 1) / 2) {
      ans.push_back(0);
    }
    ans.push_back(n % 9 + 1);
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) {
      cout << x;
    }
    reverse(ans.begin(), ans.end());
    for (int i = len % 2; i < (int) ans.size(); i++) {
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}

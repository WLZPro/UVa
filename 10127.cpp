#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    int cur = 1;
    int ans = 1 % n;
    while (cur != 0) {
      cur = (cur * 10 + 1) % n;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

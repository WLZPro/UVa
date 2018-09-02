#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> v((int) 1e5 + 1, 0);
  vector<int> isSq((int) 1e5 + 1, 0);
  for (int i = 1; i * i <= (int) 1e5; i++) {
    isSq[i * i] = 1;
  }
  for (int i = 1; i <= (int) 1e5; i++) {
    v[i] = v[i - 1] + isSq[i];
  }
  int a, b;
  while (cin >> a >> b, a != 0 && b != 0) {
    cout << v[b] - v[a - 1] << endl;
  }
  return 0;
}

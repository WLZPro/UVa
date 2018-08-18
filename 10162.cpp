#include <iostream>
#include <vector>

using namespace std;

const vector<int> cyc = {1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4, 4, 5, 9, 6, 2, 7, 3, 6, 2, 1, 1, 2, 8, 1, 7, 2, 8, 5, 9, 8, 8, 9, 3, 0, 6, 1, 7, 0, 6, 5, 5, 6, 2, 5, 1, 6, 2, 9, 3, 2, 2, 3, 7, 4, 0, 5, 1, 4, 0, 9, 9, 0, 6, 9, 5, 0, 6, 3, 7, 6, 6, 7, 1, 8, 4, 9, 5, 8, 4, 3, 3, 4, 0, 3, 9, 4, 0, 7, 1, 0, 0};
const int mod = (int) cyc.size();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n;
  while (cin >> n, n != "0") {
    int idx = 0;
    for (auto& c : n) {
      idx = (idx * 10 + c - '0') % mod;
    }
    idx--;
    if (idx < 0) {
      idx = (idx + mod) % mod;
    }
    cout << cyc[idx] << endl;
  }
  return 0;
}

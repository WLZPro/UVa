#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector< vector<int> > cyc = { { 0 },{ 1 },{ 2, 4, 8, 6 },{ 3, 9, 7, 1 },{ 4, 6 },{ 5 },{ 6 },{ 7, 9, 3, 1 },{ 8, 4, 2, 6 },{ 9, 1 } };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  while (cin >> s >> t, s != "0" && t != "0") {
    int m = s[(int)s.length() - 1] - '0';
    int n = 0;
    for (auto& c : t) {
      n = ((n * 10) + c - '0') % (int)cyc[m].size();
    }
    n--;
    if (n < 0) {
      n = (n + (int) cyc[m].size()) % (int) cyc[m].size();
    }
    cout << cyc[m][n] << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;  

const int OFFSET = 1000;

int n, k;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const string dir = "nesw";
vector<string> ans;
vector< vector<int> > a;
vector< vector<int> > was;

void solve(int len, int x, int y, string cur, int last) {
  if (len == k + 1) {
    if (x == 0 && y == 0) {
      ans.push_back(cur);
    }
    return;
  }
  int left = k * (k + 1) / 2 - len * (len - 1) / 2;
  if ((int) (abs(x) + abs(y)) > left) {
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (i == last || i == last + 2 || i == last - 2) {
      continue;
    }
    int newX = x;
    int newY = y;
    int pos = 1;
    for (int j = 0; j < len; j++) {
      newX += dx[i];
      newY += dy[i];
      if (a[newX + OFFSET][newY + OFFSET]) {
        pos = 0;
        break;
      }
    }
    if (pos && !was[newX + OFFSET][newY + OFFSET]) {
      was[newX + OFFSET][newY + OFFSET] = 1;
      solve(len + 1, newX, newY, cur + dir[i], i);
      was[newX + OFFSET][newY + OFFSET] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> k >> n;
    a.assign(2000, vector<int>(2000, 0));
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      a[y + OFFSET][x + OFFSET] = 1;
    }
    ans.clear();
    was.assign(2000, vector<int>(2000, 0));
    solve(1, 0, 0, "", -100);
    sort(ans.begin(), ans.end());
    for (auto& x : ans) {
      cout << x << '\n';
    }
    cout << "Found " << (int) ans.size() << " golygon(s).\n\n";
  }
  return 0; 
}

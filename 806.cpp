#include <bits/stdc++.h>
using namespace std;

void explore(int r1, int c1, int r2, int c2, vector<int>& out, const vector< vector<int> > grid, basic_string<int> curpath) {
  int sum = grid[r2][c2];
  if (r1 > 0) {
    sum -= grid[r1 - 1][c2];
  }
  if (c1 > 0) {
    sum -= grid[r2][c1 - 1];
  }
  if (r1 > 0 && c1 > 0) {
    sum += grid[r1 - 1][c1 - 1];
  }
  if (sum == 0) {
    return;
  }
  if (sum == (r2 - r1 + 1) * (c2 - c1 + 1)) {
    reverse(curpath.begin(), curpath.end());
    int res = 0;
    for (auto& x : curpath) {
      res = res * 5 + x;
    }
    out.push_back(res);
    return;
  }
  explore(r1, c1, (r1 + r2) / 2, (c1 + c2) / 2, out, grid, curpath + 1);
  explore(r1, (c1 + c2) / 2 + 1, (r1 + r2) / 2, c2, out, grid, curpath + 2);
  explore((r1 + r2) / 2 + 1, c1, r2, (c1 + c2) / 2, out, grid, curpath + 3);
  explore((r1 + r2) / 2 + 1, (c1 + c2) / 2 + 1, r2, c2, out, grid, curpath + 4);
}

void solveImage(int n) {
  vector< vector<int> > grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
      if (i > 0) {
        grid[i][j] += grid[i - 1][j];
      }
      if (j > 0) {
        grid[i][j] += grid[i][j - 1];
      }
      if (i > 0 && j > 0) {
        grid[i][j] -= grid[i - 1][j - 1];
      }
    }
  }
  vector<int> ans;
  explore(0, 0, n - 1, n - 1, ans, grid, basic_string<int>());
  sort(ans.begin(), ans.end());
  int cnt = 0;
  for (auto& x : ans) {
    if (cnt > 0) {
      cout << ' ';
    }
    cout << x;
    cnt++;
    if (cnt == 12) {
      cnt = 0;
      cout << '\n';
    }
  }
  if (!ans.empty() && (int) ans.size() % 12 != 0) {
    cout << '\n';
  }
  cout << "Total number of black nodes = " << (int) ans.size() << '\n';
}

void fill(int r1, int c1, int r2, int c2, vector< vector<char> >& grid) {
  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) {
      grid[i][j] = '*';
    }
  }
}

void solvePaths(int n) {
  vector< vector<char> > grid(n, vector<char>(n, '.'));
  int p;
  while (cin >> p, p != -1) {
    int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;
    while (p > 0) {
      int cur = p % 5;
      p /= 5;
      if (cur == 1) {
        r2 = (r1 + r2) / 2;
        c2 = (c1 + c2) / 2;
      } else if (cur == 2) {
        r2 = (r1 + r2) / 2;
        c1 = (c1 + c2) / 2 + 1;
      } else if (cur == 3) {
        r1 = (r1 + r2) / 2 + 1;
        c2 = (c1 + c2) / 2;
      } else {
        r1 = (r1 + r2) / 2 + 1;
        c1 = (c1 + c2) / 2 + 1;
      }
    }
    fill(r1, c1, r2, c2, grid);
  }
  for (auto& v : grid) {
    for (auto& x : v) {
      cout << x;
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, qq = 1;
  while (cin >> n, n != 0) {
    if (qq > 1) {
      cout << '\n';
    }
    cout << "Image " << qq++ << '\n';
    if (n < 0) {
      solvePaths(-n);
    } else {
      solveImage(n);
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector< vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector< vector<int> > dist(n, vector<int>(m, INF));
    vector< vector<int> > best_k(n, vector<int>(m, INF));
    queue< pair<int, int> > que;
    dist[0][0] = 0;
    best_k[0][0] = 0;
    que.push({0, 0});
    while (!que.empty()) {
      int r = que.front().first;
      int c = que.front().second;
      que.pop();
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
          continue;
        }
        if (a[nr][nc] == 1) {
          if (dist[r][c] + 1 <= dist[nr][nc] && best_k[r][c] < k && best_k[r][c] + 1 < best_k[nr][nc]) {
            dist[nr][nc] = dist[r][c] + 1;
            best_k[nr][nc] = best_k[r][c] + 1;
            que.push({nr, nc});
          }
        } else {
          if (dist[r][c] + 1 < dist[nr][nc]) {
            dist[nr][nc] = dist[r][c] + 1;
            best_k[nr][nc] = 0;
            que.push({nr, nc});
          }
        }
      }
    }
    if (dist[n - 1][m - 1] == INF) {
      cout << -1 << '\n';
    } else {
      cout << dist[n - 1][m - 1] << '\n';
    }
  }
  return 0;
}

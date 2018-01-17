#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define FROM_UP 0
#define FROM_RIGHT 1
#define FROM_LEFT 2
int grid[78][78], dim, k;
long long memo[78][78][6][3];
bool visited[78][78][6][3];
long long go(int r, int c, int k_left, int state) {
    if (grid[r][c] < 0) k_left--;
    if (k_left < 0) return -INF;
    if (c < 0 || r < 0 || c > dim - 1 || r > dim - 1) return -INF;
    if (r == dim - 1 && c == dim - 1) return grid[r][c];
    if (visited[r][c][k_left][state]) return memo[r][c][k_left][state];
    long long ans = -INF;
    if (r < dim - 1) ans = max(ans, go(r + 1, c, k_left, FROM_UP) + grid[r][c]);
    if (state != FROM_LEFT && c > 0) ans = max(ans, go(r, c - 1, k_left, FROM_RIGHT) + grid[r][c]);
    if (state != FROM_RIGHT && c < dim - 1) ans = max(ans, go(r, c + 1, k_left, FROM_LEFT) + grid[r][c]);
    visited[r][c][k_left][state] = true;
    return memo[r][c][k_left][state] = ans;
}

int main() {
    int caseNow = 1;
    while (scanf("%d %d", &dim, &k), dim || k) {
        memset(memo, -1, sizeof memo);
        memset(grid, 0, sizeof grid);
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        long long ans = go(0, 0, k, FROM_UP);
        if (ans <= -900000000) {
            printf("Case %d: impossible\n", caseNow++);
        } else {
            printf("Case %d: %lld\n", caseNow++, ans);
        }
    }
}
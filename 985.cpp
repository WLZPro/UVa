#include <bits/stdc++.h>
using namespace std;

int r, c, OK = (1 << 4) - 1;
// Bitmask state: NSWE
// E = 1
// W = 1 << 1
// S = 1 << 2
// N = 1 << 3
// rot = 0 : N = up, S = down, W = left, E = right
// rot = 1 : N = right, S = left, W = up, E = down
// rot = 2 : N = down, S = up, W = right, E = left
// rot = 3 : N = left, S = right, W = down, E = up
int grid[505][505];
bool visited[505][505][4];
// State = {row, col, rot}

map<pair<pair<int, int>, int>, int> dist;

int main() {
    while (scanf("%d %d", &r, &c) == 2) {
        dist.clear();
        memset(grid, 0, sizeof grid);
        memset(visited, 0, sizeof visited);
        for (int i = 1; i <= r - 1; i++) {
            for (int j = 1; j <= c; j++) {
                char c;
                if (j == 1) scanf("\n");
                while (scanf("%c", &c), c != '\n') {
                    if (c == 'N') {
                        grid[i][j] |= (1 << 3);
                    } else if (c == 'S') {
                        grid[i][j] |= (1 << 2);
                    } else if (c == 'W') {
                        grid[i][j] |= (1 << 1);
                    } else {
                        grid[i][j] |= 1;
                    }
                }
            }
        }
        scanf("\n");
        for (int i = 1; i <= c - 1; i++) {
            char c;
            while (scanf("%c", &c), c != '\n') {
                if (c == 'N') {
                    grid[r][i] |= (1 << 3);
                } else if (c == 'S') {
                    grid[r][i] |= (1 << 2);
                } else if (c == 'W') {
                    grid[r][i] |= (1 << 1);
                } else {
                    grid[r][i] |= 1;
                }
            }
        }
        visited[1][1][0] = 1;
        queue<pair<pair<int, int>, int> > q;
        q.push(make_pair(make_pair(1, 1), 0));
        dist[make_pair(make_pair(1, 1), 0)] = 0;
        while (!q.empty()) {
            pair<pair<int, int>, int> front = q.front(); q.pop();
            int row = front.first.first, col = front.first.second, rot = front.second;
            if (row == r && col == c) continue;
            int mask = grid[row][col];
            int pos = OK & mask;
            while (pos) {
                int p = pos & -pos;
                pos -= p;
                // Up
                if ((rot == 0 && p == (1 << 3)) || (rot == 1 && p == (1 << 1)) || (rot == 2 && p == (1 << 2)) || (rot == 3 && p == 1)) {
                    if (row > 0) {
                        if (!visited[row - 1][col][rot + 1 == 4 ? 0 : rot + 1]) {
                            q.push(make_pair(make_pair(row - 1, col), rot + 1 == 4 ? 0 : rot + 1));
                            visited[row - 1][col][rot + 1 == 4 ? 0 : rot + 1] = 1;
                            dist[make_pair(make_pair(row - 1, col), rot + 1 == 4 ? 0 : rot + 1)] = dist[front] + 1;
                        }
                    }
                }
                // Down
                if ((rot == 0 && p == (1 << 2)) || (rot == 1 && p == 1) || (rot == 2 && p == (1 << 3)) || (rot == 3 && p == (1 << 1))) {
                    if (row < r) {
                        if (!visited[row + 1][col][rot + 1 == 4 ? 0 : rot + 1]) {
                            q.push(make_pair(make_pair(row + 1, col), rot + 1 == 4 ? 0 : rot + 1));
                            visited[row + 1][col][rot + 1 == 4 ? 0 : rot + 1] = 1;
                            dist[make_pair(make_pair(row + 1, col), rot + 1 == 4 ? 0 : rot + 1)] = dist[front] + 1;
                        }
                    }
                }
                // Left
                if ((rot == 0 && p == (1 << 1)) || (rot == 1 && p == (1 << 2)) || (rot == 2 && p == (1 << 0)) || (rot == 3 && p == (1 << 3))) {
                    if (col > 0) {
                        if (!visited[row][col - 1][rot + 1 == 4 ? 0 : rot + 1]) {
                            q.push(make_pair(make_pair(row, col - 1), rot + 1 == 4 ? 0 : rot + 1));
                            visited[row][col - 1][rot + 1 == 4 ? 0 : rot + 1] = 1;
                            dist[make_pair(make_pair(row, col - 1), rot + 1 == 4 ? 0 : rot + 1)] = dist[front] + 1;
                        }
                    }
                }
                // Right
                if ((rot == 0 && p == (1 << 0)) || (rot == 1 && p == (1 << 3)) || (rot == 2 && p == (1 << 1)) || (rot == 3 && p == (1 << 2))) {
                    if (col < c) {
                        if (!visited[row][col + 1][rot + 1 == 4 ? 0 : rot + 1]) {
                            q.push(make_pair(make_pair(row, col + 1), rot + 1 == 4 ? 0 : rot + 1));
                            visited[row][col + 1][rot + 1 == 4 ? 0 : rot + 1] = 1;
                            dist[make_pair(make_pair(row, col + 1), rot + 1 == 4 ? 0 : rot + 1)] = dist[front] + 1;
                        }
                    }
                }
            }
        }
        int ans = 1000000000;
        bool found = 0;
        for (int rot = 0; rot < 4; rot++) {
            if (dist.find(make_pair(make_pair(r, c), rot)) != dist.end()) {
                found = 1;
                ans = min(ans, dist[make_pair(make_pair(r, c), rot)]);
            }
        }
        if (found) printf("%d\n", ans);
        else printf("no path to exit\n");
    }
    return 0;
}

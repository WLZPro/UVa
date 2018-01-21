#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
char grid[43][12];
vector<pair<int, int> > AdjList[43][12];
bool visited[43][12];
pair<int, int> match[43][12];
vector<pair< int, int> > leftSet;
void bicolor(int r, int c, int color) {
    visited[r][c] = 1;
    for (int j = 0; j < (int) AdjList[r][c].size(); j++) {
        pair<int, int> v = AdjList[r][c][j];
        if (!visited[v.first][v.second]) {
            if (color == 0) {
                leftSet.push_back(make_pair(v.first, v.second));
            }
            bicolor(v.first, v.second, !color);
        }
    }
}

int Aug(int r, int c) {
    if (visited[r][c]) return 0;
    visited[r][c] = 1;
    for (int j = 0; j < (int) AdjList[r][c].size(); j++) {
        pair<int, int> v = AdjList[r][c][j];
        if (match[v.first][v.second] == pair<int, int>(-1, -1) || Aug(match[v.first][v.second].first, match[v.first][v.second].second)) {
            match[v.first][v.second] = make_pair(r, c);
            return 1;
        }
    }
    return 0;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        for (int i = 0; i < 43; i++) {
            for (int j = 0; j < 12; j++) {
                AdjList[i][j].clear();
            }
        }
        memset(grid, 0, sizeof grid);
        memset(visited, 0, sizeof visited);
        leftSet.clear();
        int height, width;
        scanf("%d %d", &height, &width);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) scanf("\n%c", &grid[i][j]);
                else scanf("%c", &grid[i][j]);
            }
        }
        int V = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '*') {
                    V++;
                    if (i > 0) {
                        if (grid[i - 1][j] == '*') {
                            AdjList[i][j].push_back(make_pair(i - 1, j));
                        }
                    }
                    if (i < height - 1) {
                        if (grid[i + 1][j] == '*') {
                            AdjList[i][j].push_back(make_pair(i + 1, j));
                        }
                    }
                    if (j > 0) {
                        if (grid[i][j - 1] == '*') {
                            AdjList[i][j].push_back(make_pair(i, j - 1));
                        }
                    }
                    if (j < width - 1) {
                        if (grid[i][j + 1] == '*') {
                            AdjList[i][j].push_back(make_pair(i, j + 1));
                        }
                    } 
                }
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '*' && !visited[i][j]) {
                    leftSet.push_back(make_pair(i, j));
                    bicolor(i, j, 1);
                }
            }
        }
        int MCBM = 0;
        for (int i = 0; i < 43; i++) {
            for (int j = 0; j < 12; j++) {
                match[i][j] = pair<int, int>(-1, -1);
            }
        }
        for (int l = 0; l < (int) leftSet.size(); l++) {
            memset(visited, 0, sizeof visited);
            pair<int, int> u = leftSet[l];
            MCBM += Aug(u.first, u.second);
        }
        printf("%d\n", V - MCBM);
    }
}
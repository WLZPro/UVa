#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
char grid[102][102];
vector<ii> AdjList[102][102];
unsigned long long paths[102][102];
bool vis[102][102];
vector<ii> topoOrder;

void topoSort(int x, int y) {
    vis[x][y] = 1;
    for (int j = 0; j < (int) AdjList[x][y].size(); j++) {
        ii u = AdjList[x][y][j];
        if (!vis[u.first][u.second]) {
            topoSort(u.first, u.second);
        }
    }
    topoOrder.push_back(ii(x, y));
}

int main() {
    int TC;
    scanf("%d", &TC);
    int caseNow = 1;
    while (TC--) {
        int dimension;
        scanf("%d", &dimension);
        memset(grid, 0, sizeof grid);
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                AdjList[i][j].clear();
            }
        }
        int startX = -1, startY = -1;
        for (int j = dimension - 1; j >= 0; j--) {
            for (int i = dimension - 1; i >= 0; i--) {
                if (j == dimension - 1) {
                    AdjList[i][j].push_back(ii(101, 0));
                }
                char cell;
                if (i == dimension - 1) scanf("\n%c", &cell);
                else scanf("%c", &cell);
                if (cell == 'W' && startX == -1 && startY == -1) {
                    startX = i;
                    startY = j;
                }
                grid[i][j] = cell;
                if (i < dimension - 1 && j < dimension - 1) {
                    char neigh = grid[i + 1][j + 1];
                    if (neigh == 'B') {
                        if (i < dimension - 2 && j < dimension - 2 && grid[i + 2][j + 2] == '.') {
                            AdjList[i][j].push_back(ii(i + 2, j + 2));
                        }
                    } else if (neigh == '.') {
                        AdjList[i][j].push_back(ii(i + 1, j + 1));
                    }
                }
                if (i > 0 && j < dimension - 1) {
                    char neigh = grid[i - 1][j + 1];
                    if (neigh == 'B') {
                        if (i > 1 && j < dimension - 2 && grid[i - 2][j + 2] == '.') {
                            AdjList[i][j].push_back(ii(i - 2, j + 2));
                        }
                    } else if (neigh == '.') {
                        AdjList[i][j].push_back(ii(i - 1, j + 1));
                    }
                }
            }
        }
        memset(paths, 0, sizeof paths);
        memset(vis, 0, sizeof vis);
        paths[startX][startY] = 1;
        vis[startX][startY] = 1;
        topoOrder.clear();
        topoSort(startX, startY);   
        reverse(topoOrder.begin(), topoOrder.end());
        for (int i = 0; i < (int) topoOrder.size(); i++) {
            ii v = topoOrder[i];
            for (int j = 0; j < (int) AdjList[v.first][v.second].size(); j++) {
                ii u = AdjList[v.first][v.second][j];
                paths[u.first][u.second] = (paths[u.first][u.second] + paths[v.first][v.second]) % 1000007;
            }
        }
        printf("Case %d: %d\n",caseNow++ ,(int) (paths[101][0] % 1000007));
    }
}
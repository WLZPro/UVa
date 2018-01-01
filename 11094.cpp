#include <stdio.h>
#include <string.h>

char region[25][25];
bool visited[25][25];
int max, X, Y, M, N;
char landChar;

int floodfill(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) return 0;
    if (region[x][y] != landChar) return 0;
    visited[x][y] = true;
    int ans = 1;
    if (x < M - 1 && !visited[x + 1][y]) ans += floodfill(x + 1, y);
    if (x > 0 && !visited[x - 1][y]) ans += floodfill(x - 1, y);
    if (!y) {
        if (!visited[x][N - 1]) ans += floodfill(x, N - 1);
        if (!visited[x][y + 1]) ans += floodfill(x, y + 1);
    } else if (y == N - 1) {
        if (!visited[x][y - 1]) ans += floodfill(x, y - 1);
        if (!visited[x][0]) ans += floodfill(x, 0);
    } else {
        if (!visited[x][y - 1]) ans += floodfill(x, y - 1);
        if (!visited[x][y + 1]) ans += floodfill(x, y + 1);
    }
    return ans;
}

int main() {
    while (scanf("%d %d", &M, &N) == 2) {
        max = 0;
        for (int i = 0; i < 25; i++) {
            memset(visited[i], 0, sizeof visited[i]);
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (j == 0) scanf("\n%c", &region[i][j]);
                else scanf("%c", &region[i][j]);
            }
        }
        scanf("%d %d", &X, &Y);
        landChar = region[X][Y];
        floodfill(X, Y);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && region[i][j] == landChar) {
                    int res = floodfill(i, j);
                    max = max < res ? res : max;
                }
            }
        }
        printf("%d\n", max);
    } 
}
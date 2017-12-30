#include <stdio.h>

char grid[101][101];
char* ins = new char[50000];

int main() {
    while (true) {
        int N, M, S;
        scanf("%d %d %d", &N, &M, &S);
        if (!(N || M || S)) break;
        int direction, startX, startY;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char val;
                if (j == 0) scanf("\n%c", &val);
                else scanf("%c", &val);
                //scanf("%c", &val);
                grid[i][j] = val;
                if (val == 'N') {
                    direction = 1;
                    startY = i;
                    startX = j;
                } else if (val == 'L') {
                    direction = 2;
                    startY = i;
                    startX = j;
                } else if (val == 'S') {
                    direction = 3;
                    startY = i;
                    startX = j;
                } else if (val == 'O') {
                    direction = 4;
                    startY = i;
                    startX = j;
                }
            }
        }
        int x = startX;
        int y = startY;
        int stickers = 0;
        for (int i = 0; i < S; i++) {
            char c;
            if (i == 0) scanf("\n%c", &c);
            else scanf("%c", &c);
            if (c == 'D') {
                direction++;
                if (direction == 5) direction = 1;
            } else if (c == 'E') {
                direction--;
                if (direction == 0) direction = 4;
            } else if (c == 'F') {
                if (direction == 1) {
                    if (y > 0 && grid[y - 1][x] != '#') y--;
                } else if (direction == 2) {
                    if (x < M - 1&& grid[y][x + 1] != '#') x++;
                } else if (direction == 3) {
                    if (y < N - 1&& grid[y + 1][x] != '#') y++;
                } else if (direction == 4) {
                    if (x > 0 && grid[y][x - 1] != '#') x--;
                }
                if (grid[y][x] == '*') {
                    stickers++;
                    grid[y][x] = '.';
                }
            }
        }
        printf("%d\n", stickers);
    }
}
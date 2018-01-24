#include <cstdio>

int main() {
    int row, col, downRight;
    while (scanf("%d %d %d", &row, &col, &downRight), row || col || downRight) {
        if (downRight) {
            printf("%d\n", ((row - 7) * (col - 7) + 1) / 2);
        } else {
            printf("%d\n", ((row - 7) * (col - 7)) / 2);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, ans, ok;
bool allowed[16][16];

void backtrack(int colNow, int rw, int rd, int ld) {
    if (rw == ok) ans++;
    int pos = ok & (~(rw | rd | ld));
    while (pos) {
        int p = pos & -pos;
        pos -= p;
        if (allowed[(int) log2(p)][colNow]) {
            backtrack(colNow + 1, rw | p, (rd | p) << 1, (ld | p) >> 1);
        }
    }
}

int main() {
    int caseNow = 1;
    while (scanf("%d", &n), n) {
        memset(allowed, 0, sizeof allowed);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                if (j) scanf("%c", &c);
                else scanf("\n%c", &c);
                allowed[i][j] = c == '.';
            }
        }
        ans = 0;
        ok = (1 << n) - 1;
        backtrack(0, 0, 0, 0);
        printf("Case %d: %d\n", caseNow++, ans);
    }
}
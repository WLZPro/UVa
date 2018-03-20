#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[6];
int c[8][7];
int *memo;
int ind;
int combos;

int solve(int left1, int left2, int left3, int left4, int left5, int left6, int i) {
    int idx = left1 + left2 * 10 + left3 * 100 + left4 * 1000 + left5 * 10000 + left6 * 100000 + i * 1000000;
    if (left1 < 0 || left2 < 0 || left3 < 0 || left4 < 0 || left5 < 0 || left6 < 0) return 1e+9;
    if (left1 == 0 && left2 == 0 && left3 == 0 && left4 == 0 && left5 == 0 && left6 == 0) return 0;
    if (i == combos) return left1 * a[0] + left2 * a[1] + left3 * a[2] + left4 * a[3] + left5 * a[4] + left6 * a[5];
    if (memo[idx] != -1) return memo[idx];
    int ans = 1e+9;
    ans = min(ans, c[i][6] + solve(left1 - c[i][0], left2 - c[i][1], left3 - c[i][2], left4 - c[i][3], left5 - c[i][4], left6 - c[i][5], i));
    //if (idx == 869) printf("%d %d %d %d %d %d %d\n", left1 - c[i][0], left2 - c[i][1], left3 - c[i][2], left4 - c[i][3], left5 - c[i][4], left6 - c[i][5], i);
    ans = min(ans, solve(left1, left2, left3, left4, left5, left6, i + 1));
    if (ans == 1e+9) printf("%d\n", idx);
    return memo[idx] = ans;
}

int main() {
    
    while (scanf("%d", &ind) == 1) {
        for (int i = 0; i < ind; i++) {
            scanf("%d", a + i);
        }
    
        scanf("%d", &combos);
        memset(c, 0, sizeof c);
        for (int i = 0; i < combos; i++) {
            for (int j = 0; j < ind; j++) {
                scanf("%d", &c[i][j]);
            }
            scanf("%d", &c[i][6]);
        }
    
        int TC;
        scanf("%d", &TC);
        while (TC--) {
            memo = new int[10000000];
            memset(memo, -1, sizeof (int) * 10000000);
            int t[6];
            memset(t, 0, sizeof t);
            for (int i = 0; i < ind; i++) scanf("%d", t + i);
            printf("%d\n", solve(t[0], t[1], t[2], t[3], t[4], t[5], 0));
        }
    }
    return 0;
}

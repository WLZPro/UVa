#include <bits/stdc++.h>
using namespace std;
int tank_time, w, tr, depth[33], gold[33], memo[33][1003]/*[33]*/;
vector<int> dAns, gAns;
int dive(int i, int tank_left/*, int tr_taken*/) {
    if (tank_left < 0) return -1000000000;
    if (i == tr) return 0;
    if (memo[i][tank_left] != -1) {
        //printf("memoized: %d, %d\n", i, tank_left);
        return memo[i][tank_left];
    }
    int res = max(dive(i + 1, tank_left /*,tr_taken*/), gold[i] + dive(i + 1, tank_left - 3 * w * depth[i] /*,tr_taken + 1*/));
    memo[i][tank_left] = res;
    return res;
}

void print_ans(int i, int tank_left/*, int tr_taken*/) {
    if (tank_left < 0 || i == tr) return;
    if (dive(i + 1, tank_left) == memo[i][tank_left]) {
        print_ans(i + 1, tank_left);
    } else {
        print_ans(i + 1, tank_left - 3 * w * depth[i]);
        dAns.push_back(depth[i]);
        gAns.push_back(gold[i]);
    }
}

int main() {
    bool start = 1;
    while (scanf("%d %d", &tank_time, &w) == 2) {
        memset(memo, -1, sizeof memo);
        memset(depth, 0, sizeof depth);
        memset(gold, 0, sizeof gold);
        gAns.clear();
        dAns.clear();
        scanf("%d", &tr);
        for (int i = 0; i < tr; i++) {
            scanf("%d %d", &depth[i], &gold[i]);
        }
        if (!start) printf("\n");
        else start = 0;
        printf("%d\n", dive(0, tank_time/*, 0*/));
        print_ans(0, tank_time);
        printf("%d\n", (int) dAns.size());
        for (int i = (int) dAns.size() - 1; i >= 0; i--) {
            printf("%d %d\n", dAns[i], gAns[i]);
        }
    }
}
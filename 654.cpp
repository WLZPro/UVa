#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, start = 1;
    while (scanf("%d %d", &n, &m) == 2) {
        if (start) start = 0;
        else printf("\n");
        double division = (double) n / (double) m;
        int bestDen = -1, bestNum = 1;
        for (int i = 1; i <= m; i++) {
            int num = round(division * i);
            if (abs((double) num / (double) i - division) < abs((double) bestNum / (double) bestDen - division)) {
                printf("%d/%d\n", num, i);
                bestDen = i;
                bestNum = num;
            }
        }
    }
}
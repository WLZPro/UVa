#include <bits/stdc++.h>
using namespace std;

int fib[50], q[105];

int main() {
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int val;
            scanf("%d", &val);
            int idx = 0;
            while (fib[idx] != val) idx++;
            q[i] = idx;
        }   
        char ans[105], line[105];
        scanf("\n");
        fgets(line, 105, stdin);
        memset(ans, 0, sizeof ans);
        int idx = 0;
        int maxI = 0;
        for (int i = 0; i < N; i++) {
            while (line[idx] < 65 || line[idx] > 90) idx++;
            ans[q[i]] = line[idx];
            if (q[i] > maxI) maxI = q[i];
            idx++;
        }
        for (int i = 0; i <= maxI; i++) {
            printf("%c", ans[i] == 0 ? ' ' : ans[i]);
        }
        printf("\n");
    }
}
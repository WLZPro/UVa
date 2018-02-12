#include <bits/stdc++.h>
using namespace std;

int A[62505], B[62505], LIS[62505], pos[62505];

int main() {
    int TC, caseNow = 1;
    scanf("%d", &TC);
    while (TC--) {
        int n, p, q;
        memset(pos, 1000000000, sizeof pos);
        scanf("%d %d %d", &n, &p, &q);
        p++; q++;
        for (int i = 0; i < p; i++) {
            scanf("%d", &A[i]);
            pos[A[i]] = i;
        }
        for (int i = 0; i < q; i++) {
            int val;
            scanf("%d", &val);
            B[i] = pos[val] + 1;
        }
        int ans = 0;
        for (int i = 0; i < q; i++) {
            LIS[i] = 1;
            for (int j = 0; j < i; j++) {
                if (B[j] < B[i]) LIS[i] = max(LIS[i], LIS[j] + 1);
            }
            ans = max(ans, LIS[i]);
        }
        printf("Case %d: %d\n",caseNow++ ,ans);
    }
}
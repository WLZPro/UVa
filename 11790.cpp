#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int TC, caseNow = 1;
    scanf("%d", &TC);
    while (TC--) {
        int n;
        scanf("%d", &n);
        vector<int> h(n), w(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &h[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
        }
        vector<int> LIS(n), LDS(n);
        int maxLIS = 0, maxLDS = 0;
        for (int i = 0; i < n; i++) {
            LIS[i] = w[i];
            LDS[i] = w[i];
            int tmp = 0;
            int tmp2 = 0;
            for (int j = 0; j < i; j++) {
                if (h[j] < h[i]) {
                    tmp = max(tmp, LIS[j]);
                } else if (h[j] > h[i]) {
                    tmp2 = max(tmp2, LDS[j]);
                }
            }
            LIS[i] += tmp;
            maxLIS = max(maxLIS, LIS[i]);
            LDS[i] += tmp2;
            maxLDS = max(maxLDS, LDS[i]);
        }
        printf("Case %d. ", caseNow++);
        if (maxLIS >= maxLDS) {
            printf("Increasing (%d). Decreasing (%d).", maxLIS, maxLDS);
        } else {
            printf("Decreasing (%d). Increasing (%d).", maxLDS, maxLIS);
        }
        printf("\n");
    }   
    return 0;
}
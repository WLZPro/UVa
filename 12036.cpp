#include <cstdio>
#include <cstring>

int freq[102];

int main() {
    int TC, caseNow = 1;
    scanf("%d", &TC);
    while (TC--) {
        memset(freq, 0, sizeof freq);
        int n;
        scanf("%d", &n);
        bool stable = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                scanf("%d", &val);
                freq[val]++;
                if (freq[val] > n) stable = 0;
            }
        }
        printf("Case %d: %s\n",caseNow++ ,stable ? "yes" : "no");
    }
}
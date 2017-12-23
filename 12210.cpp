#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int bachelors[10000];
int spinsters[10000];
int main() {
    int caseNow = 1;
    while (true) {
        int B, S;
        scanf("%d %d", &B, &S);
        if (B == 0 && S == 0) break;
        for (int i = 0; i < B; i++) {
            scanf("%d", &bachelors[i]);
        }
        for (int i = 0; i < S; i++) {
            scanf("%d", &spinsters[i]);
        }
        sort(bachelors, bachelors + B);
        sort(spinsters, spinsters + S);
        if (B > S) {
            printf("Case %d: %d %d\n", caseNow, B - S, bachelors[0]);
        } else {
            printf("Case %d: 0\n", caseNow);
        }
        caseNow++;
    }
}

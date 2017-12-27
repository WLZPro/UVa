#include <stdio.h>
#include <algorithm>

using namespace std;

int A[2010], LISArr[2010], LDSArr[2010];

int LIS(int i) {
    if (i == 0) return 1;
    else {
        int result = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                int a = LISArr[j] + 1;
                if (a > result) {
                    result = a;
                }
            }    
        }
        
        return result;
    }
}

int LDS(int i) {
    if (i == 0) return 1;
    else {
        int result = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i]) {
                int a = LDSArr[j] + 1;
                if (a > result) {
                    result = a;
                }
            }    
        }
        return result;
    }
}

void calcLISArr(int n) {
    for (int i = 0; i < n; i ++) {
        LISArr[i] = LIS(i);
    }
}

void calcLDSArr(int n) {
    for (int i = 0;i < n; i++) {
        LDSArr[i] = LDS(i);
    }
}


int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        
        int n;
        scanf("%d", &n);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        for (int i = n; i > 0; i--) {
            scanf("%d", &A[i-1]);
        }
        int res = 1;

        calcLDSArr(n);
        calcLISArr(n);

        for (int i = 0; i < n; i++) {
            res = max(res, LISArr[i] + LDSArr[i] - 1);
        }
        printf("%d\n", res);
    }
}
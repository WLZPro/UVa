#include <stdio.h>
#include <string.h>

long long int A[100][100];

int main() {
    int TC, caseNow = 1;
    scanf("%d" , &TC);
    while (TC--) {
        memset(A, 0, sizeof A);
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%lld", &A[i][j]);
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        long long int plotSize = 0, plotPrice = 0;
        bool start = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = i; k < N; k++) {
                    for (int l = j; l < M; l++) {
                        long long int size = (k - i + 1) * (l - j + 1);
                        long long int price = A[k][l];
                        if (i > 0) price -= A[i - 1][l];
                        if (j > 0) price -= A[k][j - 1];
                        if (i > 0 && j > 0) price += A[i - 1][j - 1];
                        if (size > plotSize && price <= K) {
                            plotSize = size;
                            plotPrice = price;
                            start = false;
                        } else if (size == plotSize) {
                            if (!start) {
                                if (price < plotPrice) {
                                    plotPrice = price;
                                }
                            } else {
                                plotPrice = price;
                                start = false;
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: %lld %lld\n", caseNow++, plotSize, plotPrice);
    }
}
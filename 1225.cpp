#include <cstdio>
#include <cstring>
int freq[10];

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N;
        scanf("%d", &N);
        memset(freq, 0, sizeof freq);
        for (int i = 1; i <= N; i++) {
            int tmp = i;
            while (tmp) {
                freq[tmp % 10]++;
                tmp /= 10;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (i > 0) printf(" ");
            printf("%d", freq[i]);
        }
        printf("\n");
    }
}
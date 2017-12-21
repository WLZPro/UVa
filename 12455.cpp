

#include <string.h>
#include <stdio.h>

int main() {
    int cases;
    scanf("%d", &cases);
    int* bars = new int[20];
    for (int i = 0; i < cases; i++) {
        int X;
        scanf("%d", &X);
        int pieces;
        scanf("%d", &pieces);
        for (int j = 0; j < pieces; j++) {
            scanf("%d", bars + j);
        }
        bool found = false;
        for (int j = 0; j < (1 << pieces); j++) {
            int sum = 0;
            for (int k = 0; k < pieces; k++) {
                if ((j & (1 << k)) != 0) {
                    sum += bars[k];
                }
            }
            if (sum == X) {
                found = true;
                break;
            }
        }
        if (found) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    delete bars;
}
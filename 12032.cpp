#include <stdio.h>

int* heights = new int[100000];
int n, cases;
bool canplace(int k) {
    int heightNow = 0, factor = k;
    for (int i = 0; i < n; i++) {
        int height = heights[i] - heightNow;
        if (height > factor) {
            return false;
        } else if (height == factor) {
            factor--;
        }
        heightNow = heights[i];
    }
    return true;
}

int main() {
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        scanf("%d", &n);
        int k = 0;
        int prev = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", heights + j);
            int dist = heights[j] - prev;
            if (dist > k) {
                k = dist;
            }
            prev = heights[j];
        }
        if (!canplace(k)) {
            k++;
        }
        printf("Case %d: %d\n", i + 1, k);
    }
    
}
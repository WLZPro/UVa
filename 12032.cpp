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
        for (int j = 0; j < n; j++) {
            scanf("%d", heights + j);
        }
        int hi = 1000000000, lo = 1, mid;
        while (hi >= lo) {
            mid = (hi + lo) / 2;
            bool can = canplace(mid);
            if (can) {
                if (!(canplace(mid - 1))) {
                    break;
                }
                hi = mid - 1;
            }  else {
                lo = mid + 1;
            }   
        }
        printf("Case %d: %d\n", i + 1, mid);
    }
    
}
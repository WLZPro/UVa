#include <stdio.h>

int main() {
    int n, s;
    while (scanf("%d %d", &n, &s) == 2) {
        int a[100005];
        int i;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int cur_sum = 0, cur_size = 0, min_size = 1e+9;
        int ptr_1 = 0, ptr_2 = 0;
        while (ptr_2 < n) {
            cur_sum += a[ptr_2++];
            cur_size++;
            if (cur_sum >= s) {
                while (cur_sum - a[ptr_1] >= s && ptr_1 < n) {
                    cur_sum -= a[ptr_1++];
                    cur_size--;
                }
                min_size = cur_size < min_size ? cur_size : min_size;
            }
        }
        printf("%d\n", min_size == 1e+9 ? 0 : min_size);
    }
    return 0;
}
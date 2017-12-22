#include <stdio.h>
using namespace std;
int n;
int main() {
    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        scanf("%d", &n);
        int val = 1, sum = 0;
        int prev;
        scanf("%d", &prev);
        sum = prev;
        for (int j = 1; j < n; j++) {
            int c;
            scanf("%d", &c);
            if (j == 1) {
                prev = c;
                continue;
            }
            if (sum + prev < c) {
                val++;
                sum += prev;
            }
            prev = c;
        }
        val++;
        printf("%d\n", val);
    }
}


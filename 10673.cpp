#include <bits/stdc++.h>
using namespace std;

long long x, y, d;

void euclid(int a, int b) {
    if (b == 0) {x = 1; y = 0; d = a; return;}
    euclid(b, a%b);
    int oldy = y;
    y = x - (a/b) * y;
    x = oldy;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int x1, k;
        scanf("%d %d", &x1, &k);
        int a = ceil((double) x1 / (double) k);
        int b = floor((double) x1 / (double) k);
        euclid(a, b);
        x *= x1 / d;
        y *= x1 / d;
        printf("%lld %lld\n", y, x);
        if (a * x + b * y != x1) {
            printf("ERROR:%d case\n", TC);
        }
        //printf("a (%d) * x (%lld) + b (%d) * y (%lld) = %lld\n", a, x, b, y, a * x + b * y);
    }
}

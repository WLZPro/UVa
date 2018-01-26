#include <cmath>
#include <cstdio>

int main() {
    int n;
    while (scanf("%d", &n), n) {
        printf("%d\n", (int) log2(n));
    }
}
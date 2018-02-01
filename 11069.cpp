#include <cstdio>
#include <cstring>
using namespace std;

int fib[78];

int main() {
    memset(fib, 0, sizeof fib);
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 76; i++) {
        fib[i] = fib[i - 2] + fib[i - 3];
    }
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", fib[n] + fib[n - 1]);
    }
}
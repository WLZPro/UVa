#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long memo[53][350];

long long c(int n, int k) {
    if (memo[n][k] != -1) return memo[n][k];
    long long res;
    if (k == 0 || k == n) res = 1;
    else res = c(n - 1, k - 1) + c(n - 1, k);
    return memo[n][k] = res;
}

long long S(int n) {
    if (n == 1 || n == 2) return (long long) 1;
    return (3 * (2 * n - 3) * S(n - 1) - (n - 3) * S(n - 2)) / n;
}

long long cat(int n) {
    if (n == 1) return 0;
    return c(2 * n, n) / (n + 1);
}

int main() {
    int n;
    memset(memo, -1, sizeof memo);
    while (scanf("%d", &n) == 1) {
        long long res = n == 2 ? 0 : S(n) - cat(n - 1);
        cout << res << endl;
    }
}
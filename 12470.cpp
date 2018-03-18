#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000009;

struct matrix {
    long long mat[3][3];
};

matrix mul(matrix a, matrix b) {
    matrix ans; int k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (ans.mat[i][j] = k = 0; k < 3; k++) {
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD;
                ans.mat[i][j] %= MOD;
            }
        }
    }
    return ans;
}

matrix pow(matrix p, long long b) {
    matrix ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans.mat[i][j] = (i == j);
        }
    }
    while (b) {
        if (b & 1) ans = mul(ans, p);
        p = mul(p, p);
        b >>= 1;
    }
    return ans;
}

int main() {
    long long n;
    while (scanf("%lld", &n), n) {
        matrix ans = pow({
            {
                {0, 1, 0},
                {0, 0, 1},
                {1, 1, 1}
            }
        }, n);
        printf("%lld\n", ans.mat[1][1]);
    }
    return 0;
}
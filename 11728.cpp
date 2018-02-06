#include <bits/stdc++.h>
using namespace std;

bitset<1010> bs;
vector<int> primes;
long long memo[1010];

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= 1001; i++) {
        if (bs[i]) {
            for (int j = i * i; j <= 1001; j += i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}

long long sumDiv(long long n) {
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    long long pf_idx = 0, pf = primes[pf_idx], ans = 1;
    while (pf * pf <= n) {
        long long power = 0;
        while (n % pf == 0) {n /= pf; power++;}
        ans *= ((long long) pow((double) pf, power + 1.0) - 1) / (pf - 1);
        pf = primes[++pf_idx];
    }
    if (n != 1) ans *= ((long long) pow((double) n, 2.0) - 1) / (n - 1);
    return memo[n] = ans;
}

int main() {
    int n, caseNow = 1;
    sieve();
    memset(memo, -1, sizeof memo);
    while (scanf("%d", &n), n) {
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            long long sum = sumDiv(i);
            if (sum == n) {
                ans = i;
            }
        }
        printf("Case %d: %d\n", caseNow++, ans);
        //cout << sumDiv(n) << "\n";
    }
}
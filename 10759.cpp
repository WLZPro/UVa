#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int n, x;
ll memo[30][160];

ll dice(int dice_left, int val_now) {
    if (dice_left == 0) {
        if (val_now >= x) return 1;
        else return 0;
    }
    if (memo[dice_left][val_now] != -1) return memo[dice_left][val_now];
    ll ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += dice(dice_left - 1, val_now + i);
    }
    return memo[dice_left][val_now] = ans;
}


ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    while (cin >> n >> x, n || x) {
        memset(memo, -1, sizeof memo);
        ll cases = pow(6, n);
        ll ans = dice(n, 0);
        ll divisor = gcd(cases, ans);
        ans /= divisor;
        cases /= divisor;
        if (ans == 0) {
            cout << "0\n";
        } else if (ans == cases) {
            cout << "1\n";
        } else {
            cout << ans << "/" << cases << "\n";
        }
        
    }
}
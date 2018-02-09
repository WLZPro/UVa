#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (scanf("%d %d", &n, &m) == 2) {
        long long ans = 1;
        for (int i = n; i >= n - m + 1; i--) {
            ans *= i;
            while (ans % 10 == 0) {
                ans /= 10;
            }
            ans = ans % 1000000000;
        }
        cout << ans%10 << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
string s;
int memo[1000][1000];        

int len(int l, int r) {
    if (l == r) return 1;
    if (l + 1 == r) return s[l] == s[r] ? 2 : 1;
    if (memo[l][r] != -1) return memo[l][r];
    int &ans = memo[l][r];
    if (s[l] == s[r]) ans = 2 + len(l + 1, r - 1);
    else ans = max(len(l, r - 1), len(l + 1, r));
    return ans;
}

int main() {
    int TC;
    cin >> TC;
    getline(cin, s);
    while (TC--) {
        getline(cin, s);
        memset(memo, -1, sizeof memo);
        int ans = s.length() == 0 ? 0 : len(0, s.length() - 1);
        cout << ans << "\n";
    }
    return 0;
}

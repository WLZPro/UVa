#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, m;

string op1[1005], op2[1005];

int val1[1005], val2[1005];

ii memo[1005][1005];



bool vis[1005][1005];

ii solve(int i, int j) {
    if (i == n || j == m) {
        return ii(0, 0);
    }
    if (vis[i][j]) return memo[i][j];
    ii ans = ii(0, 0);
    if (op1[i] == op2[j]) {
        ans = solve(i + 1, j + 1);
        ans.first += val1[i] + val2[j];
        ans.second++;
    } 
    ii p = solve(i + 1, j);
    if (ans.first < p.first) {
        ans.first = p.first;
        ans.second = p.second;
    } else if (ans.first == p.first) {
        ans.second = min(ans.second, p.second);
    }
    p = solve(i, j + 1);
    if (ans.first < p.first) {
        ans.first = p.first;
        ans.second = p.second;
    } else if (ans.first == p.first) {
        ans.second = min(ans.second, p.second);
    }
    vis[i][j] = 1;
    return memo[i][j] = ans;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        memset(vis, 0, sizeof vis);
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s >> op1[i] >> val1[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s >> op2[i] >> val2[i];
        }
        
        ii ans = solve(0, 0);
        printf("%d %d\n", ans.first, ans.second);
        
    }
    return 0;
}
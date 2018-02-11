#include <bits/stdc++.h>
using namespace std;
#define MAX_N 120
string strings[MAX_N];

int main() {
    int TC;
    cin >> TC;
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while (TC--) {
        int n, k;
        cin >> n >> k;
        int ans = n;
        for (int i = 0; i < k; i++) {
            cin >> strings[i];
            //getline(cin, strings[i]);
        }
        if (k == 1) {
           cout << ans << "\n";
           continue; 
        }
        for (int i = 1; i < k; i++) {
            ans += n;
            for (int j = 0; j < n; j++) {   
                bool res = 1;
                for (int l = 0; l < n - j; l++) {
                    if (strings[i-1][j + l] != strings[i][l]) {
                        res = 0;
                        break;
                    }
                }
                if (res) {
                    ans -= n - j;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
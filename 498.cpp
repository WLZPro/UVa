#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<int> c;
vector<int> x;
int main() {
    int val;
    char checkEnd;
    while (scanf("%d%c", &val, &checkEnd) == 2) {
        c.clear(), x.clear();
        int n = 0;
        c.push_back(val);
        if (checkEnd != '\n' && checkEnd != '\0') {
            while (true) {
                scanf("%d%c", &val, &checkEnd);
                c.push_back(val);
                ++n;
                if (checkEnd == '\n' || checkEnd == '\0') break;
            }
        }
        while (true) {
            scanf("%d%c", &val, &checkEnd);
            x.push_back(val);
            if (checkEnd == '\n' || checkEnd == '\0') break;
        }
        for (int i = 0; i < (int) x.size(); i++) {
            long long ans = 0;
            int tmp = x[i];
            for (int j = n; j >= 0; j--) {
                ans += c[j] * pow(tmp, n - j);
            }
            if (i) printf(" ");
            cout << ans;
        }
        printf("\n");
    }
}
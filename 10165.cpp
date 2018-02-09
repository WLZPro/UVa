#include <bits/stdc++.h>
using namespace std;

int main() {
    int stones;
    while (scanf("%d", &stones), stones) {
        int ans;
        scanf("%d", &ans);
        for (int i = 1; i < stones; i++) {
            int val;
            scanf("%d", &val);
            ans ^= val;
        }
        printf("%s\n", ans == 0 ? "No" : "Yes");
    }
}
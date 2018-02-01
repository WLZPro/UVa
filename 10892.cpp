#include <bits/stdc++.h>

using namespace std;
vector<int> divisors;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
    int x;
    while (scanf("%d", &x), x) {
        divisors.clear();
        int limit = sqrt(x) + 1, ans = 0;
        for (int i = 1; i <= limit; i++) {
            if (i * i <= x && x % i == 0) {
                divisors.push_back(i);
                if (x != i * i) divisors.push_back(x/i);
            }
        }
        for (int i = 0; i < (int) divisors.size(); i++) {
            for (int j = i; j < (int) divisors.size(); j++) {
                if (lcm(divisors[i], divisors[j]) == x) ans++;
            }
        }
        printf("%d %d\n",x ,x == 1 ? 1 : ans);
    }
}
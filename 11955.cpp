#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long memo[53][350];

long long c(int n, int k) {
    if (memo[n][k] != -1) return memo[n][k];
    long long res;
    if (k == 0 || k == n) res = 1;
    else res = c(n - 1, k - 1) + c(n - 1, k);
    return memo[n][k] = res;
}

int main() {
    int TC, caseNow = 1;;
    scanf("%d", &TC);
    memset(memo, -1, sizeof memo);
    while (TC--) {
        char t[255], h[255];
        memset(t, 0, sizeof t);
        memset(h, 0, sizeof h);
        int power, t_pos = 0, h_pos = 0;
        scanf("%*c%*c");
        while (true) {
            char c;
            scanf("%c", &c);
            if (c == '+') break;
            t[t_pos++] = c;
        }
        while (true) {
            char c;
            scanf("%c", &c);
            if (c == ')') break;
            h[h_pos++] = c;
        }
        scanf("%*c");
        scanf("%d", &power);
        int first_pow = power, second_pow = 0;
        int k = 0;
        printf("Case %d: ", caseNow++);
        while (first_pow >= 0) {
            if (first_pow < power) printf("+");
            long long coefficient = c(power, k++);
            bool factor_added = 0;
            if (coefficient != 1) {
                if (factor_added) printf("*");
                cout << coefficient;
                factor_added = 1;
            }
            if (first_pow) {
                if (factor_added) printf("*");
                printf("%s", t);
                if (first_pow != 1) {
                    printf("^%d", first_pow);
                }
                factor_added = 1;
            }
            first_pow--;
            if (second_pow) {
                if (factor_added) printf("*");
                printf("%s", h);
                if (second_pow != 1) {
                    printf("^%d", second_pow);
                }
                factor_added = 1;
            }
            second_pow++;
        }
        printf("\n");
    }
}
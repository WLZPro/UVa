#include <bits/stdc++.h>
using namespace std;

int diffPF[1000005];
bitset<1000005> squareFree;
int mu[1000005];
vector<int> over(1000005);

int main() {
    squareFree.set();
    squareFree[1] = 1;
    mu[1] = 1;
    for (int i = 1; i <= 1000000; i++) over[i] = i;
    for (int i = 2; i <= 1000000; i++) {
        if (diffPF[i] == 0) {
            for (int j = i; j <= 1000000; j += i) {
                if (over[j] % i == 0) {
                    over[j] /= i;
                    bool square = 0;
                    while (over[j] % i == 0) {
                        square = 1;
                        over[j] /= i;
                    }
                    if (square) {squareFree[j] = 0;mu[j]=0;}
                } 
                diffPF[j]++;
                if (squareFree[j]) {
                    if (diffPF[j] % 2 == 0) {
                        mu[j] = 1;
                    } else {
                        mu[j] = -1;
                    }
                }
            }
        }
    }
    int n;
    while (scanf("%d", &n), n) {
        int m = 0;
        for (int i = 1; i <= n; i++) {
            m += mu[i];
            //printf("%d\n", mu[i]);
        }
        printf("%8d%8d%8d\n", n, mu[n], m);
    }
}

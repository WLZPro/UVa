#include <bits/stdc++.h>
using namespace std;

int a0, farr[120];

int f(int x) {
    return (x * x / 100) % 10000;
}

int main() {
    while (scanf("%d", &a0), a0) {
        int tortoise = f(a0), hare = f(f(a0));
        while (tortoise != hare){
            tortoise = f(tortoise);
            hare = f(f(hare));
        }
        int mu = 0; hare = a0;
        while (tortoise != hare) {
            tortoise = f(tortoise);
            hare = f(hare);
            mu++;
        }
        int lambda = 1; hare = f(tortoise);
        while (tortoise != hare) {
            hare = f(hare);
            lambda++;
        }
        printf("%d\n", mu + lambda);
    }
}

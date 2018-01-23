#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
    long long N;
    while (cin >> N, N >= 0) {
        long long limit = (long long) sqrt(N) + 1;
        long long cur = -1;
        for (int i = limit; i >= 1; i--) {
            long long coco = N;
            bool possible = 1;
            for (int j = 0; j < i; j++) {
                long long divide = (coco - 1) / i;
                if (coco % i != 1) {
                    possible = 0;
                    break;
                }
                coco -= (divide + 1);
            }
            if (coco % i != 0) possible = 0;
            if (possible) {
                cur = i;
                break;
            }
        }
        if (cur == -1) {
            cout << N << " coconuts, no solution" << endl;
        } else {
            cout << N << " coconuts, " << cur << " people and 1 monkey" << endl;
        }
        
    }
}
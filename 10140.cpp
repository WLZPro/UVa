#include <bits/stdc++.h>
using namespace std;
bitset<47010> bs;
vector<int> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= 47000; i++) {
        if (bs[i]) {
            for (long long j = i * i; j <= 47000; j += i) {
                bs[j] = 0;
            }
            primes.push_back((int) i);
        }
    }
}

bool prime(long long n) {
    if (n <= 47000) return bs[n];
    for (int i = 0; i < (int) primes.size(); i++) {
        if (n % primes[i] == 0) return false;
    }
    return true;
}

int main() {
    unsigned int x, y;
    sieve();
    while (scanf("%d %d", &x, &y) == 2) {
        int prev = -1, totalPrimes = 0;
        int max_diff = -1, min_diff = 1000010000;
        pair<int, int> far;
        pair<int, int> near;
        for (int i = x; i <= y; i++) {
            if (prime(i)) {
                totalPrimes++;
                if (prev != -1) {
                    int diff = i - prev;
                    if (diff > max_diff) {
                        max_diff = diff;
                        far = make_pair(prev, i);
                    }
                    if (diff < min_diff) {
                        min_diff = diff;
                        near = make_pair(prev, i);
                    }
                }
                prev = i;
            }
        }
        if (totalPrimes < 2) printf("There are no adjacent primes.\n");
        else printf("%d,%d are closest, %d,%d are most distant.\n", near.first, near.second, far.first, far.second);
    }
}
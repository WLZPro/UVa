#include <bits/stdc++.h>
using namespace std;
bitset<10000010> bs;
vector<int> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= 10000001; i++) {
        if (bs[i]) {
            for (long long j = i * i; j <= 10000001; j += i) {
                bs[j] = 0;
            }
            primes.push_back((int)i);
        }
    }
}


int main() {
    long long n;
    sieve();
    while (cin >> n, n) {
        if (n < 0) n = -n;

        int nbrPrimes = 0;
        long long largestPrime = -1;

        for (int i = 0; i < (int)primes.size(); i ++) {
            if (n % primes[i] == 0) {
                largestPrime = primes[i];
                nbrPrimes ++;
                while (n % primes[i] == 0) {
                    n /= primes[i];
                }
                if (n == 1) break;
            }
        }


        if ((n > 1)&&(nbrPrimes > 0)) {
            largestPrime = n;
        }

        if ((n == 1)&&(nbrPrimes == 1)) largestPrime = -1;

        cout << largestPrime << "\n";
    }
}
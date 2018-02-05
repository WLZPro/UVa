#include <bits/stdc++.h>
using namespace std;

bitset<10000010> bs;
vector<int> primes;

int _sieve_size;
void sieve(int size) {
    _sieve_size = size + 1;
    bs.set();
    bs[1] = bs[0] = 0;
    for (int i = 2; i * i <= _sieve_size; i++) {
        if (bs[i]) {
            for (int j = i * i; j <= _sieve_size; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}



int main() {
    int TC;
    scanf("%d", &TC);
    sieve(10000000);
    while (TC--) {
        int a, c;
        scanf("%d %d", &a, &c);
        //printf("test case %d:%d %d\n",TC,a,c);
        if (c % a != 0) printf("NO SOLUTION\n");
        else {
            int pf = primes[0], pf_idx = 0;
            int b = 1;
            while (c != 1) {
                int factor = 1;
                while (c % pf == 0) {
                    c /= pf;
                    factor*=pf;
                }
                if (a % factor != 0) b *= factor;
                pf_idx++;
                if (pf_idx < (int) primes.size()) pf = primes[pf_idx];
                else pf = c; 
            }
            printf("%d\n", b);
        }
    }
}
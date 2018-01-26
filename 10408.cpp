#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int gcd(int i, int j) {
    while ( j != 0) {
        int r = i % j;
        i = j;
        j = r;
    }
    return i;
}
struct fraction {
    int numerator;
    int denominator;
};
bool fractionCompare(fraction &a, fraction &b) {
    return (double) a.numerator / (double) a.denominator < (double) b.numerator / (double) b.denominator;
}
vector<fraction> fractions;
int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        fractions.clear();
        fraction special;
        special.numerator = 1;
        special.denominator = 1;
        fractions.push_back(special);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) == 1) {
                    fraction frac;
                    frac.denominator = i;
                    frac.numerator = j;
                    fractions.push_back(frac);
                }
            }
        }
        sort(fractions.begin(), fractions.end(), fractionCompare);
        printf("%d/%d\n", fractions[k - 1].numerator, fractions[k - 1].denominator);
    }
}
#include <cstdio>
#include <cmath>
double doubleBase = sqrt(2);


int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int n;
        scanf("%d", &n);
        double out;
        if (n == 1) {
            out = 0.000;
        } else if (n == 2) {
            out = 4.000;
        } else {
            double base = doubleBase;
            double intBase = (n - 2) * (n - 2);
            base *= intBase;
            double doub = (double) n;
            base += (doub * doub) - intBase;
            out = base;
        }
        printf("%.3f\n", out);
        if (TC > 0) printf("\n");
    }
}
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, d;
    while (scanf("%d %d", &n, &d), n || d) {
        vector<int> digits;
        bool repeated = 1;
        int vis[1005];
        int residual, res;
        memset(vis, -1, sizeof vis);

        vis[n] = 0;
        while (1) {
            n *= 10;

            res = n / d;
            residual = n % d;
            
            digits.push_back(res);

            if (!residual) {
                repeated = 0;
                break;
            }

            if (vis[residual] >= 0) {
                break;
            }

            vis[residual] = (int) digits.size();
            n = residual;
        }
        printf(".");

        int i = 0;
        while (i < (int) digits.size()) {
            printf("%d", digits[i]);
            i++;
            if (i % 50  == 49) {
                printf("\n");
            }
            
        }
        if (i % 50 != 49) printf("\n");

        if (repeated) {
            printf("The last %d digits repeat forever.", (int) digits.size() - vis[residual] );
        } else {
            printf("This expansion terminates.");
        }
        printf("\n\n");
    }
    return 0;
}

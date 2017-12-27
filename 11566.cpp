#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int flavorIndex[210];
int prices[210];
int N, x, T, k, maxPrice, limit;
int* memo = NULL;

int take (int i, int takenNow, int dishes) {

    int index = (i*(limit) + takenNow)*(2*(N+1)) + dishes;
    if (memo[index]) return memo[index]; 

    if (dishes == 2 * (N+1)) return 0;
    if (i == k * 2 ) return 0;

    if (takenNow == limit) {
        return memo[index] = 0;
    }
    
    if (prices[i] > limit - takenNow) return memo[index] = take(i + 1, takenNow, dishes);

    else return memo[index] = max(take(i + 1, takenNow, dishes), flavorIndex[i] + take(i + 1, takenNow + prices[i], dishes + 1));
}

int main() {
    memo = new int[201 * 1000 * 22];
    while (true) {        
        scanf("%d %d %d %d", &N, &x, &T, &k);
        if (!(N || x || T || k)) break;
        maxPrice = (N + 1) * x;
        memset(memo, 0, sizeof (int) * 201 * 1000 * 22);
        limit = floor((double) maxPrice / 1.1 - (double) (N+1) * (double) T + 0.0001);
        for (int i = 0; i < k; i++) {
            int price;
            scanf("%d", &price);
            prices[i * 2] = price;
            prices[i * 2 + 1] = price;
            int flavor;
            flavorIndex[i*2] = flavorIndex[i*2+1] = 0;
            for (int j = 0; j < N + 1; j++) {
                scanf("%d", &flavor);
                flavorIndex[i * 2] += flavor;
                flavorIndex[i * 2 + 1] += flavor;
            }
        }
        printf("%.2f\n", ((double) take(0,0,0) ) / ((double) N + 1));
    }
}

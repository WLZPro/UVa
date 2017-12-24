#include <stdio.h>
#include <bitset>
#include <string.h>

using namespace std;

int S[100];
bitset<100> isB;
int main() {
    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        memset(S, 0, sizeof S);
        isB.reset();
        int end, stones;
        scanf("%d %d", &stones, &end);
        for (int j = 0; j < stones; j++) {
            char stone;
            int val;
            scanf("\n%c-%d", &stone, &val);
            if (stone == 'B') {
                isB.set(j);
            }
            S[j] = val;
        }
        int current = -1, max = 0, posNow = 0;
        while (current < stones - 1) {
            if (!isB.test(current + 1)) {
                current += 2;
            } else {
                current++;
            }
            if (current == stones) {
                break;
            }
            int dist = S[current] - posNow;
            posNow = S[current];
            if (!isB.test(current)) {
                S[current] = -1;
            }
            if (dist > max) {
                max = dist;
            }
        }
        int dist = end - posNow;
        if (dist > max) {
            max = dist;
        }
        posNow = end;
        current = stones;
        while (true) {
            while (S[current - 1] == -1) {
                --current;
            }
            current--;
            if (current < 0) {
                break;
            }
            int dist = posNow - S[current];
            if (dist > max) {
                max = dist;
            }
            posNow = S[current];
        }
        printf("Case %d: %d\n", i + 1, max);
    }
}

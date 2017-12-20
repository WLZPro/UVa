#include <stdio.h>
#include <string.h>
int main() {
    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        bool solved = false;
        int x, y,z;
        for (x = -22; x <= 22 && !solved; x++) {
            if (x * x <= c) {
                for (y = -100; y <= 100 && !solved; y++) {
                    if (x != y && x*x + y*y <= c) {
                        for (z = -100; z <= 100 && !solved; z++) {
                            if (x != y && y != z && z != x && x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
                                    printf("%d %d %d\n", x, y, z);
                                solved = true;
                            }
                        }
                    }

                }
            }

        }
        if (!solved) {
            printf("No solution.\n");
        }
    }
}


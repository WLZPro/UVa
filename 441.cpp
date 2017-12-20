#include <stdio.h>
#include <string.h>
int main() {
    int* arr = new int[13];
    int numbers;
    bool start = true;
    while (scanf("%d", &numbers)) {
        if (numbers == 0) break;
        else if (start == false) printf("\n");
        start = false;
        for (int i = 0; i < numbers; i++) {
            scanf("%i", arr + i);
        }
        for (int a = 0; a < numbers - 5; ++a) {
            for (int b = a + 1; b < numbers - 4; ++b) {
                for (int c = b + 1; c < numbers - 3; ++c) {
                    for (int d = c + 1; d < numbers - 2; ++d) {
                        for (int e = d + 1; e < numbers - 1; ++e) {
                            for (int f = e + 1; f < numbers; ++f) {
                                printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
                            }
                        }
                    }
                }
            }
        }
    }
    delete arr;
}

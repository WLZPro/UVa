#include <stdio.h>
#include <string.h>
int main() {
   int cases;
   scanf("%i", &cases);
   int* arr = new int[1000];
   for (int i = 0; i < cases; i++) {
        memset(arr, 0, sizeof (int) * 1000);
        int aLn;
        scanf("%i", &aLn);
        for (int j = 0; j < aLn; j++) {
            scanf("%i", arr + j);
        }
        int ans = 0;
        for (int j = 1; j < aLn; j++) {
            int tmp = arr[j];
            for (int k = 0; k < j; k++) {
                if (arr[k] <= tmp) {
                    ++ans;
                }
            }
        }
        printf("%i\n", ans);
   }
   delete arr;
}

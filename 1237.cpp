#include <stdio.h>
#include <cstring>
using namespace std;

int main() {
    int cases;
    int* low = new int[10000];
    int* high = new int[10000];
    char ** names = new char*[10000];
    char *pMem = new char[10000*21];
    for (int i = 0; i < 10000; i ++) {
        names[i] = pMem + i*21;
    }
    scanf("%i", &cases);
    for (int i = 0; i < cases; i++) {
        memset(low, 0, sizeof (int) * 10000);
        memset(high, 0, sizeof (int) * 10000);
        memset(pMem,0, sizeof(char) * 10000 * 21);

        int d;
        scanf("%i", &d);
        for (int j = 0; j < d; j++) {
            scanf("%s %i %i", names[j], low + j, high + j);
        }
        int q;
        scanf("%i", &q);

        char underRes[] = "UNDETERMINED";


        for (int j = 0; j < q; j++) {
            bool found = false;
            char *result = NULL;
            result = underRes;
            int val;
            scanf("%i", &val);
            for (int k = 0; k < d; k++) {
                if (val >= low[k] && val <= high[k]) {
                    if (!found) {
                        found = true;
                        result = names[k];
                    } else {
                        result = underRes;
                        break;
                    }
                }
            }
            printf("%s\n", result);
        }
        if (i < cases - 1) {
            printf("\n");
        }
    }

    delete pMem;
    delete names;
    delete low;
    delete high;
}

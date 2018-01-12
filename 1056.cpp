#include <stdio.h>
#include <map>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int AdjMat[52][52];

int main() {
    int V, E, caseNow = 1;
    while (scanf("%d %d", &V, &E), V || E) {
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                AdjMat[i][j] = 1000000000;
                if (i == j) {
                    AdjMat[i][j] = 0;
                }
            }
        }
        map<string, int> names;
        int count = 0;
        for (int i = 0; i < E; i++) {
            char name1[1000], name2[1000];
            string n1, n2;
            scanf("%s %s", name1, name2);
            n1 = name1; n2 = name2;
            map<string, int>::iterator iter = names.find(n1);
            if (iter == names.end()) {
                names.insert(make_pair(n1, count++));
            }
            map<string, int>::iterator iter2 = names.find(n2);
            if (iter2 == names.end()) {
                names.insert(make_pair(n2, count++));
            }
            int pos1 = names[n1];
            int pos2 = names[n2];
            AdjMat[pos1][pos2] = 1;
            AdjMat[pos2][pos1] = 1;
        }
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
                    AdjMat[j][i] = AdjMat[i][j];
                }
            }
        }
        int maxLen = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                maxLen = max(maxLen, AdjMat[i][j]);
            }
        }
        if (maxLen == 1000000000) {
            printf("Network %d: DISCONNECTED\n\n", caseNow++);
        } else {
            printf("Network %d: %d\n\n", caseNow++, maxLen);
        }
    }
}
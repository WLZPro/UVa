#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int adjMat[102][102];

int main() {
    int TC;
    scanf("%d", &TC);
    int caseNow = 1;
    while (TC--) {
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                adjMat[i][j] = 1000000000;
            }
        }
        for (int i = 0; i < 102; i++) {
            adjMat[i][i] = 0;
        }
        int V, E;
        scanf("%d", &V);
        scanf("%d", &E);
        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adjMat[u][v] = 1;
            adjMat[v][u] = 1;
        }
        int start, end;
        scanf("%d %d", &start, &end);
        
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
        int dist = adjMat[start][0] + adjMat[0][end];


        for (int i = 1; i < V; i++) {
            dist = max(dist, adjMat[start][i] + adjMat[i][end]);
        }
        printf("Case %d: %d\n",caseNow++ ,dist);
    }
}
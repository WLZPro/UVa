#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


bool visited[1968];
vector<int> dist;
typedef pair<int, int> ii;
int n, m;

void sssp() {

}

int main() {
    char caseName[13];
    while (scanf("%s", caseName) != EOF) {
        vector<int> AdjList[123][16];
        scanf("%d %d", &n, &m);

        for (int k = 1; k < n; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    int len;
                    scanf("%d", &len);
                    AdjList[k][i].push_back(len);
                }
            }
        }
        dist.assign(2000, 1000000000);
        for (int i = 0; i < m; i ++) {
            dist[i] = 0;
        }
        
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    dist[k * m + j] = min(dist[k * m + j], dist[(k-1) * m + i] + AdjList[k][i][j]);
                }
            }
             
        }
        int ans = 1000000000;
        for (int i = m * (n - 1); i < m * n; i++) {
            if (dist[i] < ans) {
                ans = dist[i];
            }
        }
        ans += 2 * (n - 1);
        printf("%s\n%d\n",caseName ,ans);
    }
}
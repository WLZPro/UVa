#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

vector<int> adjList[2505];
bool visited[2505];

int main() {
    int employees;
    scanf("%d", &employees);
    for (int i = 0; i < employees; i++) {
        int N;
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            int k;
            scanf("%d", &k);
            adjList[i].push_back(k);
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(visited, 0, sizeof visited);
        int source;
        scanf("%d", &source);
        queue<pair<int, int> > q;
        q.push(make_pair(source, 0));
        visited[source] = 1;
        int thisDay, max = 0, prev = 0, maxDay;
        while (!q.empty()) {
            pair<int, int> v = q.front(); q.pop();
            if (v.second != prev) {
                if (thisDay > max && prev != 0) {
                    max = thisDay;
                    maxDay = prev;
                }
                prev++; 
                thisDay = 0;
            }
            thisDay++;
            for (int j = 0; j < (int) adjList[v.first].size(); j++) {
                int u = adjList[v.first][j];
                if (!visited[u]) {
                    q.push(make_pair(u, prev + 1));
                    visited[u] = 1;
                }
            }
        }
        if (thisDay > max && prev != 0) {
            max = thisDay;
            maxDay = prev;
        }
        if (!max) printf("0\n");
        else printf("%d %d\n", max, maxDay);
    }
}
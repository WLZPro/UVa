#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

vector<ii> adjList[10002];
vector<int> dist(10002, -1);
vector<pair<int, ii> > edgeList;
vector<int> distFromDest(10002, -1);
vector<ii> adjList2[10002];


int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        dist.assign(10002, -1);
        distFromDest.assign(10002, -1);
        edgeList.clear();
        for (int i = 0; i < 10002; i++) {
            adjList[i].clear();
            adjList2[i].clear();
        }
        int N, M, s, t, p;
        scanf("%d %d %d %d %d", &N, &M, &s, &t, &p);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(make_pair(w, v));
            edgeList.push_back(make_pair(w, ii(u, v)));
            adjList2[v].push_back(make_pair(w, u));
        }
        priority_queue<ii> pq;
        pq.push(ii(0, s));
        dist[s] = 0;
        int max_toll = -1;
        while (!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int d = -front.first, u = front.second;
            if (d > dist[u]) continue;
            for (int j = 0; j < (int) adjList[u].size(); j++) {
                ii v = adjList[u][j];
                if (dist[v.second] == -1) {
                    dist[v.second] = dist[u] + v.first;
                    pq.push(ii(-dist[v.second], v.second));
                } else if (dist[u] + v.first < dist[v.second]) {
                    dist[v.second] = dist[u] + v.first;
                    pq.push(ii(-dist[v.second], v.second));
                }
            }
        }
        priority_queue<ii> pq2;
        pq2.push(ii(0, t));
        distFromDest[t] = 0;
        while (!pq2.empty()) {
            ii front = pq2.top(); pq2.pop();
            int d = -front.first, u = front.second;
            if (d > distFromDest[u]) continue;
            for (int j = 0; j < (int) adjList2[u].size(); j++) {
                ii v = adjList2[u][j];
                if (distFromDest[v.second] == -1) {
                    distFromDest[v.second] = distFromDest[u] + v.first;
                    pq2.push(ii(-distFromDest[v.second], v.second));
                } else if (distFromDest[u] + v.first < distFromDest[v.second]) {
                    distFromDest[v.second] = distFromDest[u] + v.first;
                    pq2.push(ii(-distFromDest[v.second], v.second));
                }
            }
        }
        for (int j = 0; j < (int) edgeList.size(); j++) {
            pair<int, ii> front = edgeList[j];
            int w = front.first, u = front.second.first, v = front.second.second;
            if (dist[u] == -1 || distFromDest[v] == -1) continue;
            int d = dist[u] + w + distFromDest[v];
            if (d <= p) {
                max_toll = max(max_toll, w);
            }
        }
        printf("%d\n", max_toll);
    }
}
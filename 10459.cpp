#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <bitset>
#include <cstring>
using namespace std;

vector<int> AdjList[5002];
int half1, half2;
priority_queue<int> best_roots;
int p[5002];
void backtrack(int u, int dist) {
    if (half1 == half2) {
        if (dist == half1) {
            best_roots.push(-u);
            return;
        }
    } else {
        if (dist == half1) {
            best_roots.push(-u);
        } else if (dist == half2) {
            best_roots.push(-u);
            return;
        }
    }
    backtrack(p[u], dist + 1);
}

int main() {
    int nodes;
    while (scanf("%d", &nodes) != EOF) {
        for (int i = 0; i < 5002; i++) {
            AdjList[i].clear();
        }
        best_roots = priority_queue<int>();
        memset(p, 0, sizeof p);
        for (int i = 1; i <= nodes; i++) {
            int u;
            scanf("%d", &u);
            for (int j = 0; j < u; j++) {
                int v;
                scanf("%d", &v);
                AdjList[i].push_back(v);
                AdjList[v].push_back(i);
            }
        }
        queue<pair<int, int> > q;
        q.push(make_pair(1, 0));
        bitset<5002> visited;
        visited[1] = true;
        priority_queue<int> worst_roots;
        
        int max_d = 0, max_v = 1;
        while (!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            int u = front.first;
            max_v = u;
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (!visited[v]) {
                    q.push(make_pair(v, 0));
                    visited[v] = true;
                }
            }
        }
        q.push(make_pair(max_v, 0));
        visited.reset();
        visited[max_v] = true;
        while (!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            int u = front.first, d = front.second;
            if (d >= max_d) {
                max_d = d;
                max_v = u;
            }
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (!visited[v]) {
                    q.push(make_pair(v, d + 1));
                    visited[v] = true;
                    p[v] = u;
                }
            }
        }
        half1 = max_d / 2;
        half2 = (max_d + 1) /2;
        backtrack(max_v, 0);

        printf("Best Roots  :");
        while (!best_roots.empty()) {
            printf(" %d", -best_roots.top());
            int s = -best_roots.top();
            best_roots.pop();
        
            visited.reset();
            visited[s] = true;
            q.push(make_pair(s, 0));
            while (!q.empty()) {
                pair<int, int> front = q.front(); q.pop();
                int u = front.first, d = front.second;
                for (int j = 0; j < (int) AdjList[u].size(); j++) {
                    int v = AdjList[u][j];
                    if (!visited[v]) {
                        q.push(make_pair(v, d + 1));
                        visited[v] = true;
                        p[v] = u;
                    }
                }
                if (d >= half2) {
                    worst_roots.push(-u);
                }
            }
        }
        printf("\nWorst Roots :");
        while (!worst_roots.empty()) {
            printf(" %d", -worst_roots.top());
            worst_roots.pop();
        }
        printf("\n");
    }
}
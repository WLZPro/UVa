#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <bitset>
using namespace std;

vector<int> AdjList[5002];

int main() {
    int nodes;
    while (scanf("%d", &nodes) != EOF) {
        for (int i = 0; i < 5002; i++) {
            AdjList[i].clear();
        }
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
        vector<int> q2;
        q.push(make_pair(1, 0));
        bitset<5002> vis;
        vis[1] = true;
        int max_dist = 0;
        int count = 0, index = 0;
        while (!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            q2.push_back(front.first);
            count ++;
            int u = front.first, d = front.second;
            if (d > max_dist) {
                max_dist = d;
                index = count;
            }
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(make_pair(v, d + 1));
                }
            }
        }
        vis.reset();
        priority_queue<int> worst_roots;
        for (int i = index; i < (int) q2.size(); i++) {
            q.push(make_pair(q2[i], 0));
            vis[q2[i]] = true;
            worst_roots.push(-q2[i]);   
        }
        max_dist = 0;
        q2.clear();
        count = 0;

        int p[2000];
        memset(p, 0, sizeof p);

        while (!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            int u = front.first, d = front.second;
            count++;
            q2.push_back(u);
            if (d > max_dist) {
                max_dist = d;
                index = count;
            }
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(make_pair(v, d + 1));
                }
            }
        }
        for (int i = index; i < (int) q2.size(); i++) {
            worst_roots.push(-q2[i]);   
        }

        
        while (!worst_roots.empty()) {
            int node_id = -worst_roots.top();
            q.push(make_pair(node_id, 0));
            vis[node_id] = true;
            printf("cool dude: %d\n", node_id);
            worst_roots.pop();
        }

    }
}
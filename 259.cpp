#include <stdio.h>
#include <string.h>
#include <vector>
#include <bitset>
#include <queue>
#define INF 1000000000
using namespace std;

int f;
vector<int> p;
int res[40][40];
vector<int> AdjList[40];
void augment(int v, int minEdge) {
    if (v == 0) {f = minEdge; return;}
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}
int main() {
    char inputLine[255];
    bool start = 1;
    while (fgets(inputLine, 255, stdin)) {
        memset(res, 0, sizeof res);
        for (int i = 0; i < 40; i++) {
            AdjList[i].clear();
        }
        for (int i = 27; i < 37; i++) {
            res[i][37] = 1;
            AdjList[i].push_back(37);
        }
        int expectedMf = 0;
        while (1) {
            if (start) {
                start = 0;
            } else {
                if (!fgets(inputLine, 255, stdin)) {
                    break;
                }
            }
            char applicationName = inputLine[0];
            if (applicationName == '\n' || applicationName == '\0') break;
            int alphabetPos = applicationName - 'A' + 1;
            int amount = inputLine[1] - '0';
            expectedMf += amount;
            res[0][alphabetPos] = amount;
            AdjList[0].push_back(alphabetPos);
            int pos = 3;
            while (1) {
                char conn = inputLine[pos++];
                if (conn == ';') break;
                int conni = conn - '0' + 27;
                res[alphabetPos][conni] = INF;
                AdjList[alphabetPos].push_back(conni);
                AdjList[conni].push_back(alphabetPos);
            }
        }
        int mf = 0;
        while (1) {
            f = 0;
            bitset<40> vis; vis[0] = true;
            vector<int> dist(40, INF); dist[0] = 0;
            queue<int> q; q.push(0);
            p.assign(40, -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == 37) break;
                for (int j = 0; j < (int) AdjList[u].size(); j++) {
                    int v = AdjList[u][j];
                    if (res[u][v] > 0 && !vis[v]) {
                        vis[v] = true, q.push(v), p[v] = u;
                    }
                }
            }
            augment(37, INF);
            if (f == 0) break;
            mf += f;
        }

        if (mf == expectedMf) {
            for (int i = 27; i < 37; i++) {
                char out = '_';
                for (int j = 1; j <= 26; j++) {
                    if (res[i][j] != 0) {
                        out = j - 1 + 'A';
                        break;
                    }
                }
                printf("%c", out);
            }
            printf("\n");
        } else {
            printf("!\n");
        }
        //printf("%d %d", expectedMf, mf);
        start = 1;
    }
    /*
            char inputLine[255];
            while(fgets(inputLine,255, stdin)){
                printf("%s\n",inputLine);
            }
            printf("read input end");
            return 0;
            */
            
            
    
}
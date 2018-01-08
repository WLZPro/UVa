#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

vector<vector<int> > maze(1002, vector<int>(1002));
vector<vector<int> > dist(1002, vector<int>(1002));

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        maze.assign(1002, vector<int> (1002));
        int N, M;
        scanf("%d", &N);
        scanf("%d", &M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &maze[i][j]);
            }
        }
        for (int i = 0; i < 1002; i++) {
            dist[i].assign(1002, 1000000000);
        }
        priority_queue<pair<int, ii> > pq;
        pq.push(make_pair(-maze[0][0], ii(0, 0)));
        dist[0][0] = maze[0][0];
        while (!pq.empty()) {
            pair<int, ii> front = pq.top(); pq.pop();
            int d = -front.first; ii v = front.second;
            int x = v.first, y = v.second;
            if (d > dist[x][y]) continue;
            if (x > 0) {
                if (dist[x][y] + maze[x - 1][y] < dist[x - 1][y]) {
                    dist[x - 1][y] = dist[x][y] + maze[x - 1][y];
                    pq.push(make_pair(-dist[x - 1][y], ii(x - 1, y)));
                }
            }
            if (x < N - 1) {
                if (dist[x][y] + maze[x + 1][y] < dist[x + 1][y]) {
                    dist[x + 1][y] = dist[x][y] + maze[x + 1][y];
                    pq.push(make_pair(-dist[x + 1][y], ii(x + 1, y)));
                }
            }
            if (y > 0) {
                if (dist[x][y] + maze[x][y - 1] < dist[x][y - 1]) {
                    dist[x][y - 1] = dist[x][y] + maze[x][y - 1];
                    pq.push(make_pair(-dist[x][y - 1], ii(x, y - 1)));
                }
            }
            if (y < M - 1) {
                if (dist[x][y] + maze[x][y + 1] < dist[x][y + 1]) {
                    dist[x][y + 1] = dist[x][y] + maze[x][y + 1];
                    pq.push(make_pair(-dist[x][y + 1], ii(x, y + 1)));
                }
            }
        }
        printf("%d\n", dist[N - 1][M - 1]);
    }
}
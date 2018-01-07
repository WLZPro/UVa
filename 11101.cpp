#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


vector<vector<bool> > grid(2010, vector<bool>(2010, 0));
vector<vector<int> > dist(2010, vector<int>(2010, 0));


int main() {
    int p1, p2;
    while (scanf("%d", &p1), p1) {
        for (int i = 0; i < 2010; i++) {
            grid[i].assign(2010, 0);
            dist[i].assign(2010, -1);
        }
        queue<pair<int, int> > q;
        int maxX = -1, maxY = -1, minX = 3000, minY = 3000;
        for (int i = 0; i < p1; i++) {
            int a, s;
            scanf("%d %d", &a, &s);
            maxX = max(maxX, a);
            minX = min(minX, a);
            maxY = max(maxX, s);
            minY = min(minX, s);
            grid[a][s] = 1;
            dist[a][s] = 0;
            q.push(make_pair(a, s));
        }
        scanf("%d", &p2);
        for (int i = 0; i < p2; i++) {
            int a, s;
            scanf("%d %d", &a, &s);
            maxX = max(maxX, a);
            minX = min(minX, a);
            maxY = max(maxX, s);
            minY = min(minX, s);
            grid[a][s] = 1;
        }
        int min_dist = 10000;
        while(!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            if (front.first < maxX && dist[front.first + 1][front.second ] == -1) {
                dist[front.first + 1][front.second] = dist[front.first][front.second] + 1;
                q.push(make_pair(front.first + 1, front.second));
                if (grid[front.first + 1][front.second]) {
                    min_dist = min(min_dist, dist[front.first + 1][front.second]);
                }
            }
            if (front.first > minX && dist[front.first - 1][front.second ] == -1) {
                dist[front.first - 1][front.second] = dist[front.first][front.second] + 1;
                q.push(make_pair(front.first - 1, front.second));
                if (grid[front.first - 1][front.second]) {
                    min_dist = min(min_dist, dist[front.first - 1][front.second]);
                }
            }
            if (front.second < maxY && dist[front.first][front.second + 1] == -1) {
                dist[front.first][front.second + 1] = dist[front.first][front.second] + 1;
                q.push(make_pair(front.first, front.second + 1));
                if (grid[front.first][front.second + 1]) {
                    min_dist = min(min_dist, dist[front.first][front.second + 1]);
                }
            }
            if (front.second > minY && dist[front.first][front.second - 1] == -1) {
                dist[front.first][front.second - 1] = dist[front.first][front.second] + 1;
                q.push(make_pair(front.first, front.second - 1));
                if (grid[front.first][front.second - 1]) {
                    min_dist = min(min_dist, dist[front.first][front.second - 1]);
                }
            } 
        }
        printf("%d\n", min_dist);
    }
}
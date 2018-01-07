#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

vector<pair<int, ii> > edgeList;
vector<int> result;

class UF {
    private: vector<int> p, rank;
    public:
        UF(int u) {
            rank.assign(u, 0);
            p.assign(u, 0);
            for (int i = 0; i < u; i++) p[i] = i;
        }
        int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]) p[y] = x;
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};


int main() {
    int V, E;
    while (scanf("%d %d", &V, &E), V || E) {
        result.clear();
        edgeList.clear();
        if (E) {
            for (int i = 0; i < E; i++) {
                 int x, y, w;
                 scanf("%d %d %d", &x, &y, &w);
                 edgeList.push_back(make_pair(w, ii(x, y)));
            }
            sort(edgeList.begin(), edgeList.end());
            UF unionFind(V);
            for (int i = 0; i < E; i++) {
                pair<int, ii> front = edgeList[i];
                if (unionFind.isSameSet(front.second.first, front.second.second)) {
                    result.push_back(front.first);
                } else {
                    unionFind.unionSet(front.second.first, front.second.second);
                }
            }
            sort(result.begin(), result.end());
            if ((int) result.size() == 0) {
                printf("forest\n");
            } else {
                for (int i = 0; i < (int) result.size(); i++) {
                    if (i) printf(" ");
                    printf("%d", result[i]);
                }
                printf("\n");
            }
            
        } else {
            printf("forest\n");
        }
    }
}
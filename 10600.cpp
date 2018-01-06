#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;

vector<pair<int, ii> > edgeList;
vector<int> mstPos;

bitset<10000> flagged;

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
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N, M;
        scanf("%d %d", &N, &M);
        edgeList.clear();
        mstPos.clear();
        flagged.reset();
        for (int i = 0; i < M; i++) {
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            edgeList.push_back(make_pair(C, ii(A, B)));
        }
        sort(edgeList.begin(), edgeList.end());
        int mst_cost = 0;
        UF set(N + 1);
        for (int i = 0; i < M; i++) {
            pair<int, ii> front = edgeList[i];
            if (!set.isSameSet(front.second.first, front.second.second)) {
                mst_cost += front.first;
                set.unionSet(front.second.first, front.second.second);
                mstPos.push_back(i);
            }
        }
        int second_mst_cost = 999999;
        for (int i = 0; i < (int) mstPos.size(); i++) {
            flagged = flagged.reset();
            flagged.set(mstPos[i]);
            int st_cost = 0;
            UF set2(N + 1);
            for (int i = 0; i < M; i++) {
                if (!flagged.test(i)) {
                    pair<int, ii> front = edgeList[i];
                    if (!set2.isSameSet(front.second.first, front.second.second)) {
                        st_cost += front.first;
                        set2.unionSet(front.second.first, front.second.second);
                    } 
                }
                
            }
            if (st_cost < second_mst_cost && st_cost >= mst_cost) {
                second_mst_cost = st_cost;
            }
        }
        printf("%d %d\n", mst_cost, second_mst_cost);
    }
}
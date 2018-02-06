#include <bits/stdc++.h>
#define MEMLIMIT 1000000

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<int> cars;

map<iii, int> memo;

int len;
int load(int i, int port, int starboard) {
    if (port > len || starboard > len) return -100000000;
    if (i == (int) cars.size()) {
        return 0;
    }
    iii idx = iii(i, ii(port, starboard));
    if (memo.find(idx) != memo.end()) return memo[idx];
    int add_port = 1 + load(i + 1, port + cars[i], starboard);
    int add_starboard = 1 + load(i + 1, port, starboard + cars[i]);
    //int dont_add = load(i + 1, port, starboard);
    int ans = max(add_port, add_starboard);
    ans = max(0, ans);
    //ans = max(ans, dont_add);
    return memo[idx] = ans;
}

void print_load(int i, int port, int starboard) {
    if (port > len || starboard > len || i == (int) cars.size()) return;
    iii idx = iii(i, ii(port, starboard));
    if (1 + load(i + 1, port + cars[i], starboard) == memo[idx]) {
        printf("port\n");
        print_load(i + 1, port + cars[i], starboard);
        return;
    }
    if (1 + load(i + 1, port, starboard + cars[i]) == memo[idx]) {
        printf("starboard\n");
        print_load(i + 1, port, starboard + cars[i]);
        return;
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    bool start = 1;
    //memo[make_pair(5, ii(6, 7))] = 5;
    //printf("%d", memo[make_pair(5, ii(6, 7))]);
    while (TC--) {
        scanf("%d", &len);
        len *= 100;
        int carLen;
        cars.clear();
        memo.clear();
        while (scanf("%d", &carLen), carLen) {
            cars.push_back(carLen);
        }
        //memo.assign((int) cars.size(), vector<vector <int> >((int) cars.size() * 3000));
        if (!start) printf("\n");
        else start = 0;
        printf("%d\n", load(0, 0, 0));
        print_load(0, 0, 0);
    }
}
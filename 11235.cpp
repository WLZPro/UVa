#include <cstdio>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define OFFSET 100000
#define INF 1000000000

struct node {
    node *l, *r;
    int val;
    int i, j;
};
vector<int> a, b, e, freq;

//build tree on [i,j]
node *build(int i, int j) {
    if (i == j) {
        return new node{NULL, NULL, freq[a[i] + OFFSET], i, j};
    } else {
        node *l = build(i, (i + j) / 2);
        node *r = build((i + j) / 2 + 1, j);
        return new node{l, r, max(l->val, r->val), i, j};
    }
}
//find minimum value on interval [i,j]
int query(node *cur, int i, int j) {
    //somtimes we just ignore the node
    if (cur->j < i || cur->i > j) {
        return -1;
    }
    //somtimes we take the value
    else if (cur->i >= i && cur-> j <= j) {
        
        return cur->val;
    }
    //sometimes we split in two
    else {
        return max(query(cur->l, i, j), query(cur->r, i, j));
    }
}


int main() {
    int n, q;
    while (scanf("%d", &n), n) {
        freq.assign(200005, 0);
        scanf("%d", &q);
        a.assign(n, 0);
        b.assign(n, 0);
        e.assign(n, n);
        int prev = INF, id_now = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            int tmp = a[i];
            freq[tmp + OFFSET]++;
            if (i > 0) {
                if (a[i] > a[i - 1]) {
                    b[i] = i;
                    int j = i - 1;
                    while (e[j] == n) {
                        e[j] = i;
                        j--;
                        if (j < 0) break;
                    }
                } else {
                    b[i] = b[i - 1];
                }
            }
        }
        node *root = build(0, n - 1);
        for (int i = 0; i < q; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            int query_begin = max(x, e[x]), query_end = min(y, b[y]);
            int ans;
            if (e[x] > y || b[y] < x) {
                ans = y - x + 1;
            } else {
                ans = query(root, query_begin, query_end - 1);
                ans = max(ans, y-b[y]+1);
                ans = max(ans, e[x]-x);
            }
            printf("%d\n", ans);
        }
    }
}

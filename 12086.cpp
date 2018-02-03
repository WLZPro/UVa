#include <bits/stdc++.h>
using namespace std;
#define min(a, b) a <= b ? a : b
#define INF 1000000000

struct node {
    node *l, *r;
    int val;
    int i, j;
};

vector<int> a;
//build tree on [i,j]
node *build(int i, int j) {
    if (i == j) {
        return new node{NULL, NULL, a[i], i, j};
    } else {
        node *l = build(i, (i + j) / 2);
        node *r = build((i + j) / 2 + 1, j);
        return new node{l, r, l->val + r->val, i, j};
    }
}
//find minimum value on interval [i,j]
int query(node *cur, int i, int j) {
    //somtimes we just ignore the node
    if (cur->j < i || cur->i > j) {
        return 0;
    }
    //somtimes we take the value
    else if (cur->i >= i && cur-> j <= j) {
        return cur->val;
    }
    //sometimes we split in two
    else {
        return query(cur->l, i, j) + query(cur->r, i, j);
    }
}


//we assume that i is in [cur->i, cur->j]
void update(node *cur, int i, int newValue) {
    if (cur->l == NULL) { // or "if (cur->i == cur->j)"
        cur->val = newValue;
    } else {
        // do we left or right?
        if (i <= cur->l->j) { // it's on the left
            update(cur->l, i, newValue);
        } else { //it's on the right
            update(cur->r, i, newValue);
        }
        //update minimum here
        cur->val = cur->l->val + cur->r->val;
    }
}

int main() {
    int n, caseNow = 1;
    while (scanf("%d", &n), n) {
        a.assign(n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if (caseNow > 1) {
            printf("\n");
        }
        printf("Case %d:\n", caseNow++);
        node *root = build(0, n - 1);
        while (1) {
            char name;
            scanf("\n%c", &name);
            if (name == 'E') {
                scanf("%*c%*c");
                break;
            } else if (name == 'M') {
                int x, y;
                scanf("%d %d", &x, &y);
                printf("%d\n", query(root, x - 1, y - 1));
            } else if (name == 'S') {
                int x, y;
                scanf("%d %d", &x, &y);
                update(root, x - 1, y);
            }
        }
    }
}
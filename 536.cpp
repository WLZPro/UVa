#include <bits/stdc++.h>
using namespace std;

string in_order, pre_order, post_order;
vector<int> ch_left, ch_right;
int n;

int build(int L1, int R1, int L2, int R2) {
  if (L1 > R1) {
    return -1;
  }
  int root = pre_order[L2];
  int p = L1;
  while (in_order[p] != root) {
    p++;
  }
  int cnt = p - L1;
  ch_left[root] = build(L1, p - 1, L2 + 1, L2 + cnt);
  ch_right[root] = build(p + 1, R1, L2 + cnt + 1, R2);
  return root;
}

void dfs(int u) {
  if (ch_left[u] != -1) {
    dfs(ch_left[u]);
  }
  if (ch_right[u] != -1) {
    dfs(ch_right[u]);
  }
  post_order += u;
}

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> pre_order >> in_order) {
    n = (int) in_order.size();
    ch_left.assign(256, -1);
    ch_right.assign(256, -1);
    post_order = "";
    dfs(build(0, n - 1, 0, n - 1));
    cout << post_order << '\n';
  }
  return 0;
}

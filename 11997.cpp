#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct heapNode {
  int val, idx;
  bool operator < (const heapNode& a) const {
    return val > a.val;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  while (cin >> k) {
    vector< vector<int> > a(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        cin >> a[i][j];
      }
      sort(a[i].begin(), a[i].end());
    }
    for (int i = 1; i < k; i++) {
      priority_queue<heapNode> pq;
      for (int j = 0; j < k; j++) {
        pq.push({a[0][j] + a[i][0], 0});
      }
      for (int j = 0; j < k; j++) {
        int val = pq.top().val;
        int idx = pq.top().idx;
        pq.pop();
        a[0][j] = val;
        if (idx < k - 1) {
          pq.push({val - a[i][idx] + a[i][idx + 1], idx + 1});
        }
      }
    }
    for (int i = 0; i < k; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << a[0][i];
    }
    cout << endl;
  }
  return 0;
}

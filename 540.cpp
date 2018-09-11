#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, qq = 1;
  while (cin >> t, t != 0) {
    vector< queue<int> > v(t);
    queue<int> que;
    vector<int> team((int) 1e6 + 1);
    for (int i = 0; i < t; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int val;
        cin >> val;
        team[val] = i;
      }
    }
    string s;
    cout << "Scenario #" << qq++ << endl;
    while (cin >> s, s != "STOP") {
      if (s == "ENQUEUE") {
        int x;
        cin >> x;
        if (v[team[x]].empty()) {
          que.push(team[x]);
        }
        v[team[x]].push(x);
      } else {
        int front_team = que.front();
        cout << v[front_team].front() << endl;
        v[front_team].pop();
        if (v[front_team].empty()) {
          que.pop();
        }
      }
    }
    cout << endl;
  }
  return 0;
}

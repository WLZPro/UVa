#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    stack<int> st;
    queue<int> que;
    priority_queue<int> pq;
    int b1 = 1, b2 = 1, b3 = 1;
    for (int i = 0; i < n; i++) {
      int type, x;
      cin >> type >> x;
      if (type == 1) {
        st.push(x);
        que.push(x);
        pq.push(x);
      } else {
        if (st.empty()) {
          b1 = b2 = b3 = 0;
          continue;
        }
        if (st.top() != x) {
          b1 = 0;              
        }
        if (que.front() != x) {
          b2 = 0;
        }
        if (pq.top() != x) {
          b3 = 0;
        }
        st.pop();
        que.pop();
        pq.pop();   
      }
    }
    if (b1 + b2 + b3 > 1) {
      cout << "not sure";
    } else if (b1 + b2 + b3 == 0) {
      cout << "impossible";
    } else {    
      if (b1) {
        cout << "stack";
      }
      if (b2) {
        cout << "queue";
      }
      if (b3) {
        cout << "priority queue";
      }
    }
    cout << endl;
  }   
  return 0;
}

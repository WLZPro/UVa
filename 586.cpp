#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct stack_item {
  int layer, mul;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    string s;
    stack<stack_item> st;
    st.push({0, 1});
    vector<int> ans(11, 0);
    while (1) {
      cin >> s;
      if (s == "END") {
        st.pop();
        if (st.empty()) {
          break;
        }
      } else if (s == "LOOP") {
        cin >> s;
        if (s == "n") {
          st.push({st.top().layer + 1, st.top().mul});
        } else {
          st.push({st.top().layer, st.top().mul * stoi(s)});
        }
      } else if (s == "OP") {
        int val;
        cin >> val;
        ans[st.top().layer] += st.top().mul * val;
      }
    }
    int first = 1;
    int none = 1;
    cout << "Program #" << qq << endl << "Runtime = ";
    for (int i = 10; i >= 0; i--) {
      if (ans[i] == 0) {
        continue;
      }
      none = 0;
      if (!first) {
        cout << '+';
      }
      if (i == 0) {
        cout << ans[i];
        continue;
      }
      first = 0;
      if (ans[i] > 1) {
        cout << ans[i] << '*';
      }
      cout << 'n';
      if (i > 1) {
        cout << '^' << i;
      }
    }
    if (none) {
      cout << '0';
    }
    cout << endl << endl;
  }
  return 0;
}

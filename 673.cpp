#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  string s;
  getline(cin, s);
  while (tt--) {
    string s;
    getline(cin, s);
    stack<char> st;
    int pos = 1;
    for (auto& c : s) {
      if (c == '(' || c == '[') {
        st.push(c);
      } else {
        if (st.empty()) {
          pos = 0;
          break;
        }
        if (c == ']') {
          if (st.top() != '[') {
            pos = 0;
            break;
          }
        } else {
          if (st.top() != '(') {
            pos = 0;
            break;
          }
        }
        st.pop();
      }
    }
    if (!st.empty()) {
      pos = 0;
    }
    if (!pos) {
      cout << "No";
    } else {
      cout << "Yes";
    }
    cout << '\n';
  }
  return 0;
}

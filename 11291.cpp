#include <iostream>
#include <string>
#include <iomanip>
#include <stack>

using namespace std;

double eval(string s) {
  if (s[0] == '(') {  
    s = s.substr(1, (int) s.length() - 2);
    double p, e1, e2;
    int i;
    for (i = 0; i < (int) s.length(); i++) {
      if (s[i] == ' ') {
        p = stod(s.substr(0, i));
        break;
      }
    } 
    i++;
    stack<char> st;
    int prev = i;
    for (; i < (int) s.length(); i++) {
      if (s[i] == '(') {
        st.push(s[i]);
      } else if (s[i] == ')') {
        st.pop();
      }
      if (s[i] == ' ' && (int) st.size() == 0) {
        break;
      }
    }
    e1 = eval(s.substr(prev, i - prev));
    e2 = eval(s.substr(i + 1));
    return p * (e1 + e2) + (1.0 - p) * (e1 - e2);
  } else {
    return (double) stoi(s);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (getline(cin, s), s != "()") {
    cout << fixed << setprecision(2) << eval(s) << endl;
  }
  return 0; 
}

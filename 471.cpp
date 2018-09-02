#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unordered_map<string, int> mp;
  vector<string> v;
  for (char c = 'a'; c <= 'z'; c++) {
    v.push_back(string(1, c));
  }
  for (char c = 'a'; c <= 'z' - 1; c++) {
    for (char c2 = c + 1; c2 <= 'z'; c2++) {
      v.push_back(string(1, c)+ string(1, c2));
    }
  }
  for (char c = 'a'; c <= 'z' - 2; c++) {
    for (char c2 = c + 1; c2 <= 'z' - 1; c2++) {
      for (char c3 = c2 + 1; c3 <= 'z'; c3++) {
        v.push_back(string(1, c) + string(1, c2) + string(1, c3));
      }
    }
  }
  for (char c = 'a'; c <= 'z' - 3; c++) {
    for (char c2 = c + 1; c2 <= 'z' - 2; c2++) {
      for (char c3 = c2 + 1; c3 <= 'z' - 1; c3++) {
        for (char c4 = c3 + 1; c4 <= 'z'; c4++) {
          v.push_back(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4));
        }
      }
    }
  }
  for (char c = 'a'; c <= 'z' - 4; c++) {
    for (char c2 = c + 1; c2 <= 'z' - 3; c2++) {
      for (char c3 = c2 + 1; c3 <= 'z' - 2; c3++) {
        for (char c4 = c3 + 1; c4 <= 'z' - 1; c4++) {
          for (char c5 = c4 + 1; c5 <= 'z'; c5++) {
            v.push_back(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5));
          }
        }
      }
    }
  }
  sort(v.begin(), v.end(), [](const string& a, const string& b) {
    if ((int) a.length() != (int) b.length()) {
      return (int) a.length() < (int) b.length();
    }
    return a < b;
  });
  for (int i = 0; i < (int) v.size(); i++) {
    mp[v[i]] = i + 1;
  }
  string s;
  while (getline(cin, s)) {
    if (!mp.count(s)) {
      cout << 0 << endl;
    } else {
      cout << mp[s] << endl;
    }
  }
  return 0;
}

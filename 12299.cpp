#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> a;

const int INF = 0x3f3f3f3f;

struct node {
  int val;
  node *left, *right;
  int i, j;
};

node* build(int i, int j) {
  if (i == j) {
    return new node{a[i], nullptr, nullptr, i, j};
  }
  node* left = build(i, (i + j) / 2);
  node *right = build((i + j) / 2 + 1, j);
  return new node{min(left->val, right->val), left, right, i, j};
}

int query(node* cur, int i, int j) {
  if (cur->i > j || cur->j < i) {
    return INF;
  }
  if (cur->i >= i && cur->j <= j) {
    return cur->val;
  }
  return min(query(cur->left, i, j), query(cur->right, i, j));
}

void update(node* cur, int i, int newVal) {
  if (cur->j < i || cur->i > i) {
    return;
  }
  if (cur->i == i && cur->j == i) {
    cur->val = newVal;
    return;
  }
  update(cur->left, i, newVal);
  update(cur->right, i, newVal);
  cur->val = min(cur->left->val, cur->right->val);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  node *root = build(0, n - 1);
  string junk;
  getline(cin, junk);
  while (q--) {
    string line;
    getline(cin, line);
    int pos;
    for (int i = 0; i < (int) line.length(); i++) {
      if (line[i] == '(') {
        pos = i;
        break;
      }
    }
    if (line[0] == 'q') {
      line = line.substr(pos + 1, (int) line.length() - pos - 2);
      stringstream ss(line);
      int i, j;
      string tmp;
      getline(ss, tmp, ',');
      i = stoi(tmp);
      getline(ss, tmp, ',');
      j = stoi(tmp);
      i--; j--;
      cout << query(root, i, j) << endl;
    } else {
      line = line.substr(pos + 1, (int) line.length() - pos - 2);
      vector<int> v;
      stringstream ss(line);
      string tmp;
      while (getline(ss, tmp, ',')) {
        v.push_back(stoi(tmp) - 1);
      }
      int first = query(root, v[0], v[0]);
      for (int i = 0; i < (int) v.size() - 1; i++) {
        update(root, v[i], query(root, v[i + 1], v[i + 1]));
      }
      update(root, v[(int) v.size() - 1], first);
    }
  }
  return 0;
}

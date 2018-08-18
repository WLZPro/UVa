#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const vector< pair<int, int> > ans = {{6, 8}, {35, 49}, {204, 288}, {1189, 1681}, {6930, 9800}, {40391, 57121}, {235416, 332928}, {1372105, 1940449}, {7997214, 11309768}, {46611179, 65918161}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (auto& p : ans) {
    for (int i = 0; i < 9 - (int) (log10((double) p.first)); i++) {
      cout << ' ';
    }
    cout << p.first;
    for (int i = 0; i < 9 - (int) (log10((double) p.second)); i++) {
      cout << ' ';
    }
    cout << p.second << endl;
  }

  return 0;
}

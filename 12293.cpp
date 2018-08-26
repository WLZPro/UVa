#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n, n != 0) {
    if (((n + 1) & n) == 0) {
      cout << "Bob";
    } else {
      cout << "Alice";
    }
    cout << endl;
  }
  return 0;
}

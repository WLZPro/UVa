#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  while (cin >> n, n != 0) {
    if (((long long) sqrt(n + .5)) * ((long long) sqrt(n + .5)) == n) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

template<typename T>
T findGcd(T a, T b) {
  if (b > a) {
    swap(a, b);
  } 
  while (b > 0) {
    T t = a % b;
    a = b;
    b = t;
  }
  return a;
}

template<typename T>
T findLcm(T a, T b) {
  return a * b / findGcd(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    long long nom = 1ll, denom = 1ll;
    for (long long i = 2; i <= (long long) n; i++) {
      long long lcm = findLcm(denom, i);
      nom *= lcm / denom;
      nom += lcm / (long long) i;
      denom = lcm;
    }
    nom *= (long long) n;
    long long gcd = findGcd(nom, denom);
    nom /= gcd;
    denom /= gcd;
    if (denom == 1) {
      cout << nom << endl;
    } else {
      long long front = nom / denom;
      nom %= denom;
      cout << string((int) log10(front) + 1, ' ') << ' ' << nom << endl;
      cout << front << ' ' << string((int) log10(denom) + 1, '-') << endl;
      cout << string((int) log10(front) + 1, ' ') << ' ' << denom << endl;
    }
  }  
  return 0;
}

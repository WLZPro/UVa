#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double mul(double p1, double p2) {
  return p1 * (1.0 - p2) + (1.0 - p1) * p2;
}

double pow(double p, int k) {
  double ans = 1.0;
  while (k > 0) {
    if (k % 2 == 0) {
      k >>= 1;
      p = mul(p, p);
    } else {
      k--;
      ans = mul(ans, p);
      k >>= 1;
      p = mul(p, p);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int N, M, P, K;
    cin >> N >> M >> P >> K;
    vector<double> p1(N + 1);
    vector<double> p2(M + 1);
    vector<double> p3(P + 1);
    for (int i = 1; i <= N; i++) {
      p1[i] = (double) (i * (N - i + 1) * 2 - 1) / (double) (N * N);
    }
    for (int i = 1; i <= M; i++) {
      p2[i] = (double) (i * (M - i + 1) * 2 - 1) / (double) (M * M);
    }
    for (int i = 1; i <= P; i++) {
      p3[i] = (double) (i * (P - i + 1) * 2 - 1) / (double) (P * P);
    }
    double ans = 0.0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        for (int k = 1; k <= P; k++) {
          double prob = p1[i] * p2[j] * p3[k];
          ans += 1.0 - pow(prob, K);
        }
      }
    }
    cout << "Case " << qq << ": " << fixed << setprecision(10) << ans << endl; 
  }
  return 0;
}

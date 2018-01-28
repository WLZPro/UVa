#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define OFFSET 2550
int arr[103], n, m, full_sum, max_memo[103][5102][52], min_memo[103][5102][52];



int calcMax(int i, int sum, int takenNum) {
    if (takenNum > min(n, m)) return -1000000000;
    if (i == n + m && takenNum == min(n, m)) return sum * (full_sum - sum);
    if (i == n + m && takenNum != min(n, m)) return -1000000000;
    if (max_memo[i][sum + OFFSET][takenNum] != -1) return max_memo[i][sum+OFFSET][takenNum];

    int res = max(calcMax(i + 1, sum + arr[i], takenNum + 1), calcMax(i + 1, sum, takenNum));
    return max_memo[i][sum+OFFSET][takenNum] = res;
}

int calcMin(int i, int sum, int takenNum) {
    if (takenNum > min(n, m)) return 1000000000;
    if (i == n + m && takenNum == min(n, m)) return sum * (full_sum - sum);
    if (i == n + m && takenNum != min(n, m)) return 1000000000;
    if (min_memo[i][sum + OFFSET][takenNum] != -1) return min_memo[i][sum+OFFSET][takenNum];

    int res = min(calcMin(i + 1, sum + arr[i], takenNum + 1), calcMin(i + 1, sum, takenNum));
    return min_memo[i][sum+OFFSET][takenNum] = res;
}


int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        full_sum = 0;
        for (int i = 0; i < n + m; i++) {
            scanf("%d", &arr[i]);
            full_sum += arr[i];
        }
        memset(max_memo, -1, sizeof max_memo);
        memset(min_memo, -1, sizeof min_memo);
        printf("%d %d\n",calcMax(0, 0, 0) ,calcMin(0, 0, 0));
    }
}
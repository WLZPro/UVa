#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define OFFSET 2550
int arr[103], n, m, full_sum, max_memo[103][5102][52], min_val;

int calcMax(int i, int sum, int takenNum) {
    if (takenNum > min_val || (i == n + m && takenNum != min_val)) return -1000000000;
    if (takenNum + n + m - i < min_val) return -1000000000; 
    if (takenNum == min_val) return max_memo[i][sum+OFFSET][takenNum] = sum * (full_sum - sum);
    if (max_memo[i][sum + OFFSET][takenNum] != -1) return max_memo[i][sum+OFFSET][takenNum];

    int res = max(calcMax(i + 1, sum + arr[i], takenNum + 1), calcMax(i + 1, sum, takenNum));
    return max_memo[i][sum+OFFSET][takenNum] = res;
}

int calcMin(int i, int sum, int takenNum) {
    if (takenNum > min_val || (i == n + m && takenNum != min_val)) return 1000000000;
    if (takenNum + n + m - i < min_val) return 1000000000; 
    if (takenNum == min_val) return max_memo[i][sum+OFFSET][takenNum] = sum * (full_sum - sum);
    if (max_memo[i][sum + OFFSET][takenNum] != -1) return max_memo[i][sum+OFFSET][takenNum];

    int res = min(calcMin(i + 1, sum + arr[i], takenNum + 1), calcMin(i + 1, sum, takenNum));
    return max_memo[i][sum+OFFSET][takenNum] = res;
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        full_sum = 0;
        for (int i = 0; i < n + m; i++) {
            scanf("%d", &arr[i]);
            full_sum += arr[i];
        }
        min_val = min(n, m);
        memset(max_memo, -1, sizeof max_memo);
        int max_ans = calcMax(0, 0, 0);
        memset(max_memo, -1, sizeof max_memo);
        int min_ans = calcMin(0, 0, 0);
        printf("%d %d\n",max_ans ,min_ans);
    }
}
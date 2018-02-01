#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;
#define OFFSET 2550
int arr[103], n, m, full_sum, max_memo[103][5102][52], min_val;

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		
		full_sum = 0;
		for (int i = 0; i < n + m; i++) {
			scanf("%d", &arr[i]);
			full_sum += arr[i];
			arr[i] += 50;
			
		}

		bitset<5102> possibleSums[103];
		min_val = min(n, m);
		possibleSums[0].set(0);

		for (int i = 0; i < n + m; i++) {
			for (int j = min_val; j > 0; j--) {
				possibleSums[j] = (possibleSums[j - 1] << arr[i]) | possibleSums[j];
			}
		}

		int max_ans = -1000000000;
		int min_ans = 1000000000;
		for (int i = 0; i < 5102; i++) {
			if (possibleSums[min_val][i]) {
				int ans = (full_sum - (i - min_val * 50)) * (i - min_val * 50);
				min_ans = min(ans, min_ans);
				max_ans = max(ans, max_ans);
			}
		}

		printf("%d %d\n", max_ans, min_ans);
	}
}
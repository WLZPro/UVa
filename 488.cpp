#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = 0; i < b; i++) {
			for (int j = 1; j <= a; j++) {
				for (int k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
				
			}
			for (int j = a - 1; j >= 1; j--) {
				for (int k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
			}
			if (!(i == b - 1 && TC == 0)) printf("\n");
		}
	}
	return 0;
}
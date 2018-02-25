#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int a, b, ans = 0, c;
	char ops, cc[5];
	while (scanf("%d%c%d%*c%s", &a, &ops, &b, cc) == 4) {
		//printf("%d %c %d = %s\n", a, ops, b, cc);
		if (cc[0] == '?') continue;
		sscanf(cc, "%d", &c);
		if (ops == '+') {
			if (a + b == c) {
				ans++;
			}
		} else if (ops == '-') {
			if (a - b == c) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
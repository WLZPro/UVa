#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, c, r1, r2;
	while (scanf("%d %d %d %d", &l, &c, &r1, &r2), l || c || r1 || r2) {
		if (l < max(r1 + r1, r2 + r2) || c < max(r1 + r1, r2 + r2)) {
			printf("N\n");
			continue;
		}
		if (max(l, c) >= r1 + r1 + r2 + r2 && min(l, c) >= max(r1 + r1, r2 + r2)) {
			printf("S\n");
			continue;
		} 
		if ((l - r1 - r2) * (l - r1 - r2) + (c - r1 - r2) * (c - r1 - r2) >= (r1 + r2) * (r1 + r2)) printf("S\n");
		else printf("N\n");
	}
	return 0;
}
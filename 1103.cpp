#include <bits/stdc++.h>
using namespace std;

int grid[205][205];
int h, w;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
bool vis[205][205];

void floodFill(int r, int c, int x) {
	if (r < 0 || r >= h + 2 || c < 0 || c >= w + 2) return;
	if (grid[r][c] != 1) return;
	grid[r][c] = x;
	for (int i = 0; i < 4; i++) {
		floodFill(r + dr[i], c + dc[i], x);
	}
}

void floodFill2(int r, int c, int x) {
	if (r < 0 || r >= h + 2 || c < 0 || c >= w + 2) return;
	if (grid[r][c] == x || vis[r][c]) return;
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		floodFill2(r + dr[i], c + dc[i], x);
	}
}

int main() {

	/*char a[3]="9c";
	char b[10];
	for (int i = 0; i < 2; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			a[i] -= '0';
		} else {
			a[i] -= 'a' - 10;
		}
		for (int j = 0; j < 4; j ++ ) {
			b[(i+1)*4 - 1 - j] = (a[i] & (1 << j)) >>j;
		}
	}
	for (int i = 0; i < 8; i ++) {
		printf("%d\n",b[i]);
	}

	exit(0);*/


    int caseNow = 1;
	while (scanf("%d %d", &h, &w), h || w) {
        memset(grid, 0, sizeof grid);
		w *= 4;
		for (int i = 0; i < h; i++) {
			grid[i][0] = 0;
			grid[i][w - 1] = 0;
		}
		for (int i = 0; i < w; i++) {
			grid[0][i] = 0;
			grid[h - 1][i] = 0;
		}
		for (int r = 0; r < h; r++) {
			char res[54];
			scanf("%s", res);
			char b[205];
			for (int i = 0; i < w / 4; i++) {
				if (res[i] >= '0' && res[i] <= '9') {
					res[i] -= '0';
				} else {
					res[i] -= 'a' - 10;
				}
				for (int j = 0; j < 4; j ++ ) {
					grid[r + 1][(i+1)*4 - 1 - j + 1] = (res[i] & (1 << j)) >>j;
				}
			}
		}
		int count = 2;
		for (int r = 0; r < h + 2; r++) {
			for (int c = 0; c < w + 2; c++) {
				if (grid[r][c] == 1) {
					floodFill(r, c, count++);
				}
			}
		}
		string codes[] = {"W", "A", "K", "J", "S", "D"};
        string ans;
        int ans_idx = 0;
		for (int i = 2; i < count; i++) {
			int ccSize = 0;
			memset(vis, 0, sizeof vis);
			for (int r = 0; r < h + 2; r++) {
				for (int c = 0; c < w + 2; c++) {
					if (grid[r][c] != i && !vis[r][c]) {
						floodFill2(r, c, i);
						ccSize++;
					}
				}
			}
			ans.append(codes[ccSize - 1]);
		}
		sort(ans.begin(), ans.end());
        printf("Case %d: ", caseNow++);
		cout << ans << "\n";
	}
}
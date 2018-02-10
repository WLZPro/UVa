#include <bits/stdc++.h>
using namespace std;

int cc[103][103], n, totalVis, cc_size;
bool vis[103][103];

void floodFill(int r, int c) {
    vis[r][c] = 1;
    int curCC = cc[r][c];
    totalVis++;
    cc_size++;
    if (r > 0 && !vis[r - 1][c] && cc[r - 1][c] == curCC ) floodFill(r - 1, c);
    if (r < n - 1 && !vis[r + 1][c] && cc[r + 1][c] == curCC) floodFill(r + 1, c);
    if (c > 0 && !vis[r][c - 1] && cc[r][c - 1] == curCC) floodFill(r, c - 1);
    if (c < n - 1 && !vis[r][c + 1] && cc[r][c + 1] == curCC) floodFill(r, c + 1);
}

int main() {
    string lineContent;
    while (getline(cin,lineContent)) {
        istringstream iss(lineContent);
        iss >> n;
        if (n <= 0) return 0;
        totalVis = 0;
        memset(cc, 0, sizeof cc);
        memset(vis, 0, sizeof vis);
        int ccNow = 1;
        for (int i = 0; i < n - 1; i++) {
            int firstR = -1, firstC = -1;
            int r, c;
            getline(cin,lineContent);
            istringstream iss2(lineContent);
            if (iss2 >> firstR >> firstC) {
                while (iss2 >> r >> c) {
                    cc[r - 1][c - 1] = ccNow;
                }
                cc[firstR - 1][firstC - 1] = ccNow;
            }
            ccNow++;
            cc_size = 0;
            if (firstR != -1) {
                floodFill(firstR - 1, firstC - 1);
            }
            if (cc_size != n) totalVis = n * n + 1;
        }
        bool needBreak = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    floodFill(i, j);
                    needBreak = 1;
                    break;
                }
            }
            if (needBreak) break;
        }
        printf("%s\n", n * n == totalVis ? "good" : "wrong");
    }  
}
#include <bits/stdc++.h>
using namespace std;

string grid[105], dict[105];
int sz;
int x[] = { -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 1, -1, 1, -1, 0, 1 };

int search2D(int row, int col, string word) {
    if (grid[row][col] != word[0]) return -1;
    int len = word.length();
    for (int dir = 0; dir < 7; dir++) {
        int k, rd = row + x[dir], cd = col + y[dir];
        for (k = 1; k < len; k++) {
            if (rd >= sz || rd < 0 || cd >= sz || cd < 0) break;
            if (grid[rd][cd] != word[k]) break;
            rd += x[dir], cd += y[dir];
        }
        if (k == len) {
            return dir;
        }     
    }
    return -1;
}
 
void patternSearch(string word) {
    bool found = 0;
    for (int row = 0; row < sz; row++) {
        for (int col = 0; col < sz; col++) {
            int dir = search2D(row, col, word);
            if (dir != -1) {
                cout << row + 1 << "," << col + 1 << " " << row + 1 + x[dir] * ((int) word.size() - 1) << "," << col + 1 + y[dir] * ((int) word.size() - 1) << "\n";
                found = 1;
            }
        }
    }
    if (!found) cout << "Not found\n";
}


int main() {
    cin >> sz;
    for (int i = 0; i < sz; i++) {
        cin >> grid[i];
    }
    int idx = 0;
    while (1) {
        string str;
        cin >> str;
        if (str[0] == '0') break;
        dict[idx++] = str;
    }
    for (int i = 0; i < idx; i++) {
        patternSearch(dict[i]);
    }
}
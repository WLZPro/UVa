#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;

int xPos[12];
int yPos[12];
int* memo = new int[11 * 2050];

int startX;
int startY;
int beepers;

int distTo(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int TSP(int i, int mask) {
    int x = (i == -1) ? startX : xPos[i];
    int y = (i == -1) ? startY : yPos[i];
    if (mask == (1 << beepers) - 1) return distTo(x, y, startX, startY);
    
    int index = -1;
    
    if (i>= 0) {
        index = (i << 11) + mask;
        if (memo[index] != -1) return memo[index];
    }
    int res;
    bool start = true;
    for (int nxt = 0; nxt < beepers; nxt++) {
        if (i != nxt && !(mask & (1 << nxt))) {
            if (start) {
                res = distTo(x, y, xPos[nxt], yPos[nxt]) + TSP(nxt,mask | (1 << nxt));
                start = false;
            } else {
                res = min(res, distTo(x, y, xPos[nxt], yPos[nxt]) + TSP(nxt,mask | (1 << nxt)));
            }
        }
    } 
    if (index >= 0 && memo[index] == -1) {
        memo[index] = res ;
    }   
    
    return /*index == -1 ? res : memo[index] =*/ res;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        memset(memo, -1, sizeof (int) * 11 * 2050);
        scanf("%*d %*d");
        scanf("%d %d", &startX, &startY);        
        scanf("%d", &beepers);
        for (int i = 0; i < beepers; i++) {
            scanf("%d %d", &xPos[i], &yPos[i]);
        }
        printf("The shortest path has length %d\n", TSP(-1, 0));
    }
}

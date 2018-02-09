#include <bits/stdc++.h>
using namespace std;

int main(){
    int TC;
    scanf("%d", &TC);
    while(TC--){
        int m, n, r, c;
        scanf("%d %d %d %d", &m, &n, &r, &c);
        if(((m - r - 1) ^ (n - c - 1 ) ^ r ^ c)!=0){
            printf("Gretel\n");
        }
        else{
            printf("Hansel\n");
        }
    }
}
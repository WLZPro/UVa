#include <cstdio>

#include<iostream>
using namespace std;
 
void binary(int num)
{
    int rem;
 
    if (num <= 1)
    {
        cout << num;
        return;
    }
    rem = num % 2;
    binary(num / 2);
    printf("%d", rem);
}

int main() {
    int n;
    while (scanf("%d", &n), n) {
        int bin = 0;
        int copy = n;
        while (n) {
            n -= n & -n;
            bin++;
        }
        printf("The parity of ");
        binary(copy);
        printf(" is %d (mod 2).\n", bin);
    }
}
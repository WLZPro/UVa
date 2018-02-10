#include <bits/stdc++.h>
using namespace std;
vector<long long> seq;

void generate() {
    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= 31; j++){
            for (int k = 0; k <= 31; k++) {
                for (int l = 0; l <= 31; l++) {
                    long long num = pow(2, i) * pow(3, j) * pow(5, k) * pow(7, l);
                    if (num <= 2000000000LL && num > 0) {
                        seq.push_back(num);
                    }
                }
            }
        }
    }
    sort(seq.begin(), seq.end());
}

int main() {
    int n;
    generate();
    while (scanf("%d", &n), n) {
        cout << "The " << n;
        if (n % 10 == 1 && (n / 10) % 10 != 1) cout << "st";
        else if (n % 10 == 2 && (n / 10) % 10 != 1) cout << "nd";
        else if (n % 10 == 3 && (n / 10) % 10 != 1) cout << "rd";
        else cout << "th";
        cout << " humble number is " << seq[n - 1] << ".\n";
    }
}
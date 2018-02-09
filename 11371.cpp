#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    while (cin >> n) {
        long long copy = n;
        long long biggest = 0;
        vector<int> digits;
        while (copy) {
            digits.push_back(-(copy % 10));
            copy /= 10;
        }
        sort(digits.begin(), digits.end());
        long long power = 1;
        while (!digits.empty()) {
            biggest += (power) * -digits.back();
            digits.pop_back();
            power *= 10;
        }
        long long smallest = 0;
        int zeros = 0;
        copy = n;
        while (copy) {
            int digit = copy % 10;
            if (digit == 0) zeros++;
            else digits.push_back(digit);
            copy /= 10;
        }
        sort(digits.begin(), digits.end());
        power = 1;
        while (digits.size() > 1) {
            smallest += power * digits.back();
            digits.pop_back();
            power *= 10;
        }
        smallest += pow(10, zeros) * power * digits.back();
        printf("%lld - %lld = %lld = 9 * %lld\n", biggest, smallest, biggest - smallest, (biggest - smallest) / 9);
        //cout << biggest << " - " << smallest << " = " << biggest - smallest << " 9 * " << (biggest - smallest) / 9 << "\n";
    }
}
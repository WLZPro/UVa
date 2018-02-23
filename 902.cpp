#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string str;
        cin >> str;
        string ans;
        int maxFreq = 0;
        map<string, int> freq;
        for (int i = 0; i < str.length() - n + 1; i++) {
            string sub = str.substr(i, n);
            freq[sub]++;
            if (freq[sub] > maxFreq) {
                maxFreq = freq[sub];
                ans = sub;
            }
        }
        cout << ans << "\n";
    }
}
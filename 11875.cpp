#include <cstdio>
#include <vector>
using namespace std;

vector<int> player_ages;
int main() {
    int caseNow = 1, TC;
    scanf("%d", &TC);
    while (TC--) {
        int players;
        scanf("%d", &players);
        player_ages.clear();
        for (int i = 0; i < players; i++) {
            int age;
            scanf("%d", &age);
            player_ages.push_back(age);
        }
        printf("Case %d: %d\n", caseNow++, player_ages[players / 2]);
    }
}
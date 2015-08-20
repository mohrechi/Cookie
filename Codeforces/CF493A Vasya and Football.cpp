#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int minute, player;
    string team, card;
    string homeName, awayName;
    cin >> homeName >> awayName;
    cin >> n;
    map<int, int> home, away;
    while (n--) {
        cin >> minute >> team >> player >> card;
        int weight = card == "y" ? 1 : 2;
        map<int, int>& cnt = team == "h" ? home : away;
        string& teamName = team == "h" ? homeName : awayName;
        if (cnt[player] < 2 && cnt[player] + weight >= 2) {
            cout << teamName << " " << player << " " << minute << endl;
        }
        cnt[player] += weight;
    }
    return 0;
}

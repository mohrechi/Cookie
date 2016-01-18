#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1000 + 5;

string s[MAXN];
int num[MAXN];
map<string, int> scores, nextS;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s[i] >> num[i];
        scores[s[i]] += num[i];
    }
    int maxScore = 0;
    for (auto score : scores) {
        maxScore = max(maxScore, score.second);
    }
    int i = 0;
    while (scores[s[i]] < maxScore || (nextS[s[i]] += num[i]) < maxScore) {
        ++i;
    }
    cout << s[i] << endl;
}

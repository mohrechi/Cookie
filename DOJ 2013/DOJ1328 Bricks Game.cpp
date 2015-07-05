#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n;
int score[MAXN];
struct Node {
    long long maxScore;
    int next;
} dp[MAXN];

Node get(int m) {
    if (m > n) {
        return {0, n + 1};
    }
    if (dp[m].maxScore != -1) {
        return dp[m];
    }
    dp[m].maxScore = score[m] + get(get(m + 1).next).maxScore;
    dp[m].next = m + 1;
    if (m + 1 <= n) {
        long long tempScore = score[m] + score[m + 1] + get(get(m + 2).next).maxScore;
        if (tempScore > dp[m].maxScore) {
            dp[m].maxScore = tempScore;
            dp[m].next = m + 2;
        }
    }
    if (m + 2 <= n) {
        long tempScore = score[m] + score[m + 1] + score[m + 2] + get(get(m + 3).next).maxScore;
        if (tempScore > dp[m].maxScore) {
            dp[m].maxScore = tempScore;
            dp[m].next = m + 3;
        }
    }
    return dp[m];
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &score[i]);
            dp[i].maxScore = -1;
        }
        cout << get(1).maxScore << endl;
    }
    return 0;
}

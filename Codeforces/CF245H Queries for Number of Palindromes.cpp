#include <bits/stdc++.h>
using namespace std;
const int MAXS = 5000 + 5;

char s[MAXS];
bool isPalin[MAXS][MAXS];
int dp[MAXS][MAXS];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        isPalin[i][i] = true;
        dp[i][i] = 1;
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            if (s[i] == s[j] && (k == 1 || isPalin[i + 1][j - 1])) {
                isPalin[i][j] = true;
                ++dp[i][j];
            }
        }
    }
    int q, l, r;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", dp[l][r]);
    }
    return 0;
}

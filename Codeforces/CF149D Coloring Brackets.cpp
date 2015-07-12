#include <bits/stdc++.h>
using namespace std;
const int MAXN = 700 + 10;
const int MOD = 1e9 + 7;

char s[MAXN];
int link[MAXN];
long long dp[MAXN][MAXN][3][3];

void calc(int l, int r);

void reduce(int l, int r) {
    if (l + 1 == r) {
        dp[l][r][0][1] = 1;
        dp[l][r][0][2] = 1;
        dp[l][r][1][0] = 1;
        dp[l][r][2][0] = 1;
    } else {
        calc(l + 1, r - 1);
        for (int aa = 0; aa < 3; ++aa) {
            for (int bb = 0; bb < 3; ++bb) {
                if (aa == bb or (aa and bb)) {
                    continue;
                }
                for (int a = 0; a < 3; ++a) {
                    if (a and a == aa) {
                        continue;
                    }
                    for (int b = 0; b < 3; ++b) {
                        if (b and b == bb) {
                            continue;
                        }
                        (dp[l][r][aa][bb] += dp[l + 1][r - 1][a][b]) %= MOD;
                    }
                }
            }
        }
    }
}

void calc(int l, int r) {
    stack<int> stk;
    int lastL = l;
    for (int i = l; i <= r; ++i) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            link[i] = stk.top();
            link[stk.top()] = i;
            stk.pop();
        }
        if (stk.size() == 0) {
            if (lastL == l and i == r) {
                reduce(lastL, i);
            } else {
                calc(lastL, i);
            }
            if (lastL != l) {
                for (int aa = 0; aa < 3; ++aa) {
                    for (int bb = 0; bb < 3; ++bb) {
                        for (int a = 0; a < 3; ++a) {
                            for (int b = 0; b < 3; ++b) {
                                if (a and a == b) {
                                    continue;
                                }
                                (dp[l][i][aa][bb] += dp[l][lastL - 1][aa][a] * dp[lastL][i][b][bb]) %= MOD;
                            }
                        }
                    }
                }
            }
            lastL = i + 1;
        }
    }
}

int main() {
    gets(s);
    int n = strlen(s);
    calc(0, n - 1);
    long long ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans += dp[0][n - 1][i][j];
        }
    }
    cout << ans % MOD << endl;
    return 0;
}

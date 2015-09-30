#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250 + 10;

long long dp[MAXN];

int main() {
    int N, M, C;
    cin >> N >> M;
    dp[0] = 1;
    for (int i = 0; i < M; ++i) {
        cin >> C;
        for (int j = C; j <= N; ++j) {
            dp[j] += dp[j - C];
        }
    }
    cout << dp[N] << endl;
    return 0;
}
